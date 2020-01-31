/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 02:59:00 by aponomar          #+#    #+#             */
/*   Updated: 2020/01/30 20:35:31 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			color;
	double		shift_x;
	double		shift_y;
	double		angle_x;
	double		angle_y;
	float		x;
	float		y;
	float		x1;
	float		y1;
	float		z;
	float		z1;
	float		x_inp;
	float		y_inp;
	float		x1_inp;
	float		y1_inp;
	float		x_step;
	float		y_step;
	int			max;
	int			switch_2d;
	float		factor_z;

	void		*mlx_ptr;
	void		*win_ptr;

}				t_fdf;

void			read_file(char *file_name, t_fdf *data);
void			bresenham(float x1, float y1, t_fdf *data);
void			draw(t_fdf *data);
void			draw_menu(t_fdf *data);
void			multiply_z(int key, t_fdf *data);
void			make_2d(int key, t_fdf *data);
void			zoom(int key, t_fdf *data);
void			move_figure(int key, t_fdf *data);
void			change_angles(int key, t_fdf *data);
float			mod(float i);
float			max_v(float a, float b);
void			isometric(t_fdf *data);
void			zoom_figure(t_fdf *data);
void			shift_figure(t_fdf *data);

#endif
