/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:41:24 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/13 19:41:39 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ship(t_mod *mod, int y, int x, void (*color)(int, t_mod*, int))
{
	int		i;
	double	pr;
	double	pi;

	color = mod->color;
	pr = (2 * x - WX) / (mod->img->zoom * WX) + mod->img->rile;
	pi = (2 * y - HY) / (mod->img->zoom * HY) + mod->img->updo;
	mod->re = pr;
	mod->im = pi;
	i = 0;
	while (++i < mod->img->imax)
	{
		mod->old_re = mod->re;
		mod->old_im = mod->im;
		mod->im = fabs((2 * mod->re * mod->im + pi));
		mod->re = fabs((pow(mod->re, 2) - pow(mod->old_im, 2) + pr));
		if ((mod->re * mod->re + mod->im * mod->im) > 4)
			break ;
	}
	if (i < mod->img->imax)
		color(i, mod, 4);
}

void	newton(t_mod *mod, int y, int x, void (*color)(int, t_mod*, int))
{
	int		i;
	double	tmp;

	color = mod->color;
	mod->re = (2 * x - WX) / (mod->img->zoom * WX) + mod->img->rile;
	mod->im = (2 * y - HY) / (mod->img->zoom * HY) + mod->img->updo;
	i = -1;
	tmp = 1.0;
	while (tmp > 0.000001 && ++i < mod->img->imax)
	{
		mod->old_re = mod->re;
		mod->old_im = mod->im;
		mod->rsq = mod->re * mod->re;
		mod->isq = mod->im * mod->im;
		tmp = pow((mod->rsq + mod->isq), 2);
		mod->re = (2 * mod->re * tmp + mod->rsq - mod->isq) / (3.0 * tmp);
		mod->im = (2 * mod->im * (tmp - mod->old_re)) / (3.0 * tmp);
		tmp = pow((mod->re - mod->old_re), 2);
		tmp += pow((mod->im - mod->old_im), 2);
	}
	if (i < mod->img->imax)
		color(i, mod, 4);
}

void	julia(t_mod *mod, int y, int x, void (*color)(int, t_mod*, int))
{
	int i;

	i = -1;
	color = mod->color;
	mod->re = (2 * x - WX) / (mod->img->zoom * WX) + mod->img->rile;
	mod->im = (2 * y - HY) / (mod->img->zoom * HY) + mod->img->updo;
	while (++i < mod->img->imax)
	{
		mod->old_re = mod->re;
		mod->old_im = mod->im;
		mod->re = pow(mod->old_re, 2) - pow(mod->old_im, 2) + mod->pr;
		mod->im = 2 * mod->old_re * mod->old_im + mod->pi;
		if ((mod->re * mod->re + mod->im * mod->im) > 4)
			break ;
	}
	if (i < mod->img->imax)
		color(i, mod, 4);
}

void	spiral(t_mod *mod, int y, int x, void (*color)(int, t_mod*, int))
{
	int i;

	i = -1;
	color = mod->color;
	mod->re = (2 * x - WX) / ((mod->img->zoom) * WX) + mod->img->rile;
	mod->im = (2 * y - HY) / ((mod->img->zoom) * HY) + mod->img->updo;
	while (++i < mod->img->imax)
	{
		mod->old_re = mod->re;
		mod->old_im = mod->im;
		mod->re = pow(mod->old_re, 2) - pow(mod->old_im, 2) + mod->sr;
		mod->im = 2 * mod->old_re * mod->old_im + mod->si;
		if ((mod->re * mod->re + mod->im * mod->im) > 4)
			break ;
	}
	if (i < mod->img->imax)
		color(i, mod, 4);
}
