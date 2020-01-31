/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:59:17 by aponomar          #+#    #+#             */
/*   Updated: 2020/01/30 20:00:58 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	multiply_z(int key, t_fdf *data)
{
	if (key == 30)
		data->factor_z += 0.5;
	if (key == 33)
		data->factor_z -= 0.5;
}

void	make_2d(int key, t_fdf *data)
{
	if (key == 67 || key == 19)
	{
		if (data->switch_2d == 0)
			data->switch_2d = 1;
		else
			data->switch_2d = 0;
	}
}

void	zoom(int key, t_fdf *data)
{
	if (key == 24 || key == 69)
		data->zoom += 5;
	if (key == 27 || key == 78)
		data->zoom -= 5;
}

void	move_figure(int key, t_fdf *data)
{
	if (key == 126 || key == 91)
		data->shift_y -= 20;
	if (key == 125 || key == 84)
		data->shift_y += 20;
	if (key == 124 || key == 88)
		data->shift_x += 20;
	if (key == 123 || key == 86)
		data->shift_x -= 20;
}

void	change_angles(int key, t_fdf *data)
{
	if (key == 89 || key == 43)
		data->angle_x += 0.1;
	if (key == 92 || key == 47)
		data->angle_x -= 0.1;
	if (key == 83 || key == 46)
		data->angle_y += 0.1;
	if (key == 85 || key == 44)
		data->angle_y -= 0.1;
}
