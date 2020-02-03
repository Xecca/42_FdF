/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:36:12 by aponomar          #+#    #+#             */
/*   Updated: 2020/02/02 15:50:33 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			pressed_key(int key, t_fdf *data)
{
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

int			main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc > 1)
	{
		data = (t_fdf*)malloc(sizeof(t_fdf));
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
		data->zoom = 20;
		data->angle_x = 0.8;
		data->angle_y = 0.8;
		data->factor_z = 1.0;
		draw(data);
		mlx_key_hook(data->win_ptr, pressed_key, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	return (0);
}
