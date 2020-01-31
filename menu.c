/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:01:25 by aponomar          #+#    #+#             */
/*   Updated: 2020/01/30 20:41:34 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"

void		draw_menu(t_fdf *fdf)
{
	int		st_pos_h;
	int		st_pos_v;
	void	*mlx;
	void	*win;

	st_pos_h = 750;
	st_pos_v = 777;
	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, st_pos_h + 55, st_pos_v += 20, 0xffffff, "Controls:");
	mlx_string_put(mlx, win, st_pos_h + 20, st_pos_v += 25, 0xffffff, "Move:\t use arrows");
	mlx_string_put(mlx, win, st_pos_h + 20, st_pos_v += 25, 0xffffff, "Zoom:\t use + or -");
	mlx_string_put(mlx, win, st_pos_h + 20, st_pos_v += 25, 0xffffff, "2D:\t use 2 or *");
	mlx_string_put(mlx, win, st_pos_h + 20, st_pos_v += 25, 0xffffff, "Resize Z:\t use [ or ]");
	mlx_string_put(mlx, win, st_pos_h + 20, st_pos_v += 25, 0xffffff, "Rotate:\t use 7 or 9");
	mlx_string_put(mlx, win, st_pos_h + 20, st_pos_v += 25, 0xffffff, "Exit:\t use 'esc'");
}
