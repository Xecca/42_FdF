/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:31:25 by aponomar          #+#    #+#             */
/*   Updated: 2020/01/30 22:40:21 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *data)
{
	data->x = (data->x - data->y) * cos(data->angle_x);
	data->y = (data->x + data->y) * sin(data->angle_y) - data->z;
	data->x1 = (data->x1 - data->y1) * cos(data->angle_x);
	data->y1 = (data->x1 + data->y1) * sin(data->angle_y) - data->z1;
}

void	zoom_figure(t_fdf *data)
{
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
}

void	shift_figure(t_fdf *data)
{
	data->x += data->shift_x;
	data->y += data->shift_y;
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
}
