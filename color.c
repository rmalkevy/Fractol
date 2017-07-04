/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:38:53 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/13 19:39:14 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	color_to_pixel(t_mod *mod)
{
	int x;
	int y;

	x = 4 * mod->x;
	y = LINE * mod->y;
	if ((x + y > 0) && (x + y < MAX) && (x < LINE) && (x >= 0))
	{
		mod->img->line[x + y] = mod->blue;
		mod->img->line[x + y + 1] = mod->green;
		mod->img->line[x + y + 2] = mod->red;
	}
}

void	get_color3(int iter, t_mod *mod, int zn)
{
	double smooth;

	smooth = iter + 1 - (log(2) / zn) / log(2);
	mod->red = (unsigned char)(sin(0.036 * smooth + 4) * 230 + 25);
	mod->green = (unsigned char)(sin(0.033 * smooth + 2) * 230 + 25);
	mod->blue = (unsigned char)(sin(0.02 * smooth + 1) * 230 + 25);
	color_to_pixel(mod);
}

void	get_color2(int iter, t_mod *mod, int zn)
{
	double smooth;

	smooth = iter + 1 - (log(2) / zn) / log(2);
	mod->red = (unsigned char)(sin(0.05 * smooth + 4) * 150 + 100);
	mod->green = (unsigned char)(sin(0.05 * smooth + 2) * 50 + 200);
	mod->blue = (unsigned char)(sin(0.05 * smooth + 1) * 55 + 200);
	color_to_pixel(mod);
}

void	get_color1(int iter, t_mod *mod, int zn)
{
	double smooth;
	double frequency;

	frequency = 0.09;
	smooth = iter + 1 - (log(log(zn)) / log(2));
	mod->red = (unsigned char)(sin(frequency * smooth + 0) * 127.5 + 127.5);
	mod->green = (unsigned char)(sin(frequency * smooth + 2) * 127.5 + 127.5);
	mod->blue = (unsigned char)(sin(frequency * smooth + 4) * 127.5 + 127.5);
	color_to_pixel(mod);
}
