/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:48:03 by aponomar          #+#    #+#             */
/*   Updated: 2020/01/30 20:45:42 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		prepare_bresenham(t_fdf *data)
{
	data->z = data->z_matrix[(int)data->y][(int)data->x] * data->factor_z;
	data->z1 = data->z_matrix[(int)data->y1][(int)data->x1] * data->factor_z;
	zoom_figure(data);
	data->color = (data->z || data->z1) ? 0x00FF00 : 0x1E63E8;
	if (data->switch_2d == 0)
		isometric(data);
	shift_figure(data);
	data->x_step = data->x1 - data->x;
	data->y_step = data->y1 - data->y;
	data->max = max_v(mod(data->x_step), mod(data->y_step));
	data->x_step /= data->max;
	data->y_step /= data->max;
}

void		bresenham(float x1, float y1, t_fdf *data)
{
	float	x;
	float	y;

	data->x = data->x_inp;
	data->y = data->y_inp;
	data->x1 = x1;
	data->y1 = y1;
	prepare_bresenham(data);
	x = data->x;
	y = data->y;
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += data->x_step;
		y += data->y_step;
	}
}

void		draw(t_fdf *data)
{
	data->y_inp = 0;
	draw_menu(data);
	while (data->y_inp < data->height)
	{
		data->x_inp = 0;
		while (data->x_inp < data->width)
		{
			if (data->x_inp < data->width - 1)
				bresenham(data->x_inp + 1, data->y_inp, data);
			if (data->y_inp < data->height - 1)
				bresenham(data->x_inp, data->y_inp + 1, data);
			data->x_inp++;
		}
		data->y_inp++;
	}
}
