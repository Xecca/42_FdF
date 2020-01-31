/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:48:03 by aponomar          #+#    #+#             */
/*   Updated: 2020/01/30 18:55:02 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	return (i < 0) ? -i : i;
}

float		max_v(float a, float b)
{
	return (a > b ? a : b);
}

void	isometric(float *x, float *y, float *x1, float *y1,  t_fdf *data)
{
	// how to rotate
	// rotate()
	*x = (*x - *y) * cos(data->angle_x);
	*y = (*x + *y) * sin(data->angle_y) - data->z;
	*x1 = (*x1 - *y1) * cos(data->angle_x);
	*y1 = (*x1 + *y1) * sin(data->angle_y) - data->z1;
	// height matrix
}

void	zoom_figure(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

void	shift_figure(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x += data->shift_x;
    *y += data->shift_y;
    *x1 += data->shift_x;
    *y1 += data->shift_y;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	// ### chage scale ###
	// added multiplier "factor_z"
	// 
	data->z = data->z_matrix[(int)y][(int)x] * data->factor_z;
	data->z1 = data->z_matrix[(int)y1][(int)x1] * data->factor_z;
	//  ### zoom ###
	zoom_figure(&x, &y, &x1, &y1, data);
	// ### color ###

	data->color = (data->z || data->z1) ? 0x00FF00 : 0x1E63E8;
	
	//  ### 3D-format ### */
	//  ### 2D. If switch_2d = 0 - isometric switch on, else equals 1 - switch off ### */
	if (data->switch_2d == 0)
		isometric(&x, &y, &x1, &y1, data);
	// 
	//  ### shift ### */
	shift_figure(&x, &y, &x1, &y1, data);
	//  ### change value on z axis ### */


	data->x_step = x1 - x;
	data->y_step = y1 - y;
	
	data->max = max_v(mod(data->x_step), mod(data->y_step));
	data->x_step /= data->max;
	data->y_step /= data->max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += data->x_step;
		y += data->y_step;	
	}
}

void	draw(t_fdf *data)
{
	int x;
	int y;
	
	y = 0;
	draw_menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
