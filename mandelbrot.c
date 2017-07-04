/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:40:43 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/13 19:41:08 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		mandel_opt(t_mod *mod, int y, int x, void (*color)(int, t_mod*, int))
{
	double optimize;
	double pr;
	double pi;

	color = mod->color;
	pr = (2 * x - WX) / (mod->img->zoom * WX) + mod->img->rile;
	pi = (2 * y - HY) / (mod->img->zoom * HY) + mod->img->updo;
	optimize = (pr * pr - 0.5 * pr + 0.0625) + pi * pi;
	if ((optimize * (optimize + (pr - 0.25)) < (pi * pi) / 4) ||
		(pr * pr + 2 * pr + 1 + pi * pi < 0.0625))
	{
		color(mod->img->imax, mod, 0);
		return (1);
	}
	return (0);
}

void	mandel(t_mod *mod, int y, int x, void (*color)(int, t_mod*, int))
{
	double	pr;
	double	pi;
	int		i;

	i = -1;
	if (mandel_opt(mod, y, x, color))
		return ;
	pr = (2 * x - WX) / (mod->img->zoom * WX) + mod->img->rile;
	pi = (2 * y - HY) / (mod->img->zoom * HY) + mod->img->updo;
	mod->re = 0;
	mod->im = 0;
	color = mod->color;
	while (++i < mod->img->imax)
	{
		mod->old_re = mod->re;
		mod->old_im = mod->im;
		mod->re = pow(mod->old_re, 2) - pow(mod->old_im, 2) + pr;
		mod->im = 2 * mod->old_re * mod->old_im + pi;
		if ((mod->re * mod->re + mod->im * mod->im) > 4)
			break ;
	}
	if (i < mod->img->imax)
		color(i, mod, 4);
}
