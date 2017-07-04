/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:14:16 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/13 19:42:38 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FRACTAL_H
# define FDF_FRACTAL_H
# include "libft/libft.h"
# include <math.h>
# include "minilibx/mlx.h"

# define WX		500
# define HY		500

# define LINE	WX * 4
# define MAX	HY * LINE

typedef struct	s_img
{
	double		zoom;
	double		rile;
	double		updo;
	int			imax;
	void		*image;
	char		*line;
}				t_img;

typedef struct	s_shape
{
	void		*mlx;
	void		*win;
	int			y;
	int			x;
	double		pr;
	double		pi;
	double		sr;
	double		si;
	double		re;
	double		im;
	double		old_re;
	double		old_im;
	double		rsq;
	double		isq;
	int			red;
	int			green;
	int			blue;
	void		*func;
	void		*color;
	int			name;
	int			stay;
	t_img		*img;
}				t_mod;

void			write_to_image(t_mod *mod);
int				my_key_funct(int keycode, t_mod *mod);
int				mouse_func(int keycode, int x, int y, t_mod *mod);
int				mouse_move(int x, int y, t_mod *mod);
void			create_image(t_mod *mod);
void			color_to_pixel(t_mod *mod);
void			get_color1(int iter, t_mod *mod, int zn);
void			get_color2(int iter, t_mod *mod, int zn);
void			get_color3(int iter, t_mod *mod, int zn);
void			mandel(t_mod *mod, int y, int x, void (*c)(int, t_mod*, int));
void			ship(t_mod *mod, int y, int x, void (*c)(int, t_mod*, int));
void			newton(t_mod *mod, int y, int x, void (*c)(int, t_mod*, int));
void			julia(t_mod *mod, int y, int x, void (*c)(int, t_mod*, int));
void			spiral(t_mod *mod, int y, int x, void (*c)(int, t_mod*, int));
#endif
