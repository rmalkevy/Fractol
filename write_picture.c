/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_picture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:17:31 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/13 19:43:33 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	clear_image(t_mod *mod)
{
	int a;

	mlx_get_data_addr(mod->img->image, &a, &a, &a);
	ft_bzero(mlx_get_data_addr(mod->img->image, &a, &a, &a), 4 * WX * HY);
	mlx_put_image_to_window(mod->mlx, mod->win, mod->img->image, 0, 0);
}

void	write_to_image(t_mod *mod)
{
	void	(*color)(int, t_mod*);
	void	(*func)(t_mod*, int, int, void*);

	mod->y = -1;
	func = mod->func;
	color = mod->color;
	clear_image(mod);
	while (++mod->y < HY)
	{
		mod->x = -1;
		while (++mod->x < WX)
			func(mod, mod->y, mod->x, color);
	}
	mlx_put_image_to_window(mod->mlx, mod->win, mod->img->image, 0, 0);
	mlx_mouse_hook(mod->win, mouse_func, mod);
	mlx_hook(mod->win, 2, 5, my_key_funct, mod);
	mlx_hook(mod->win, 6, 0, mouse_move, mod);
	mlx_loop(mod->mlx);
}
