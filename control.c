/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:39:29 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/13 19:39:53 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	addition_key_func(int keycode, t_mod *mod)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 125)
		mod->img->updo -= 0.05 / mod->img->zoom;
	else if (keycode == 126)
		mod->img->updo += 0.05 / mod->img->zoom;
	else if (keycode == 123)
		mod->img->rile += 0.05 / mod->img->zoom;
	else if (keycode == 124)
		mod->img->rile -= 0.05 / mod->img->zoom;
	else if (keycode == 82)
		mod->img->imax += 200;
	else if (keycode == 0)
		mod->stay = 0;
	else if (keycode == 1)
		mod->stay = 1;
}

void	change_color(int keycode, t_mod *mod)
{
	if (keycode == 18)
		mod->color = get_color1;
	if (keycode == 19)
		mod->color = get_color2;
	if (keycode == 20)
		mod->color = get_color3;
}

int		my_key_funct(int k, t_mod *mod)
{
	addition_key_func(k, mod);
	change_color(k, mod);
	write_to_image(mod);
	return (0);
}

int		mouse_move(int x, int y, t_mod *mod)
{
	if (mod->stay)
		if (x >= 0 && x <= WX && y >= 0 && y <= HY)
		{
			mod->pr = y * (2.0 / HY) - 1.0;
			mod->pi = x * (2.0 / WX) - 1.0;
			write_to_image(mod);
		}
	return (0);
}

int		mouse_func(int keycode, int x, int y, t_mod *mod)
{
	if (keycode == 4)
	{
		mod->img->zoom *= 1.2;
		mod->img->updo += (y - HY / 2) / (HY * 2.5) / mod->img->zoom;
		mod->img->rile += (x - WX / 2) / (WX * 2.5) / mod->img->zoom;
	}
	else if (keycode == 5)
	{
		mod->img->zoom /= 1.2;
		mod->img->updo -= (y - HY / 2) / (HY * 2.5) / mod->img->zoom;
		mod->img->rile -= (x - WX / 2) / (WX * 2.5) / mod->img->zoom;
	}
	write_to_image(mod);
	return (0);
}
