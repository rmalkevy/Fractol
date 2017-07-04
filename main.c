/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/13 19:40:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	create_image(t_mod *mod)
{
	int size_line;
	int bits;
	int en;

	mod->img->image = mlx_new_image(mod->mlx, WX, HY);
	mod->img->line = mlx_get_data_addr(mod->img->image, &bits, &size_line, &en);
}

void	init_mod(t_mod *mod)
{
	mod->img->zoom = 0.5;
	mod->img->updo = 0;
	mod->img->rile = 0;
	mod->pr = -0.7;
	mod->pi = 0.27015;
	mod->sr = -0.77469;
	mod->si = 0.12424;
	mod->color = get_color1;
	mod->stay = 1;
	if (mod->name == 1 || mod->name == 2)
		mod->img->rile = -0.8;
	mod->img->imax = 50;
	if (mod->name == 1)
		mod->func = mandel;
	else if (mod->name == 2)
		mod->func = ship;
	else if (mod->name == 3)
		mod->func = newton;
	else if (mod->name == 4)
		mod->func = julia;
	else if (mod->name == 5)
		mod->func = spiral;
}

int		name_fractal(char *fractal)
{
	if (!ft_strcmp(fractal, "mandelbrot"))
		return (1);
	if (!ft_strcmp(fractal, "ship"))
		return (2);
	if (!ft_strcmp(fractal, "newton"))
		return (3);
	if (!ft_strcmp(fractal, "julia"))
		return (4);
	if (!ft_strcmp(fractal, "spiral"))
		return (5);
	return (0);
}

int		main(int ac, char **argv)
{
	t_mod	*mod;
	t_img	*img;

	if (ac == 2)
	{
		mod = (t_mod *)malloc(sizeof(t_mod));
		img = (t_img *)malloc(sizeof(t_img));
		mod->img = img;
		mod->name = name_fractal(argv[1]);
		if (1 > mod->name || mod->name > 5)
		{
			ft_putstr("Write correct name of fractal :");
			ft_putstr("\n1) mandelbrot\n2) ship\n3) newton");
			ft_putstr("\n4) julia\n5) spiral\n");
			exit(0);
		}
		init_mod(mod);
		mod->mlx = mlx_init();
		mod->win = mlx_new_window(mod->mlx, WX, HY, "Star 42");
		create_image(mod);
		write_to_image(mod);
	}
	return (0);
}
