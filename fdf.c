/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:36:12 by aponomar          #+#    #+#             */
/*   Updated: 2020/01/30 18:29:07 by aponomar         ###   ########.fr       */
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

int		pressed_key(int key, t_fdf *data)
{
	printf("pressed key = %d\n", key);
	if (key == 53)
		exit(key);
	make_2d(key, data);
	move_figure(key, data);
	zoom(key, data);
	change_angles(key, data);
	multiply_z(key, data);
	
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf *data;
	
	if (argc > 0)
	{
		data = (t_fdf*)malloc(sizeof(t_fdf));
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
		data->zoom = 20;
		data->angle_x = 0.8;
		data->angle_y = 0.8;
		data->factor_z = 1.0;
		
		// bresenham(10, 10, 600, 300, data);
		draw(data);
		mlx_key_hook(data->win_ptr, pressed_key, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}

	while (1);
	return 0;
}