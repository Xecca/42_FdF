/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ancillary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:03:22 by aponomar          #+#    #+#             */
/*   Updated: 2020/01/30 20:04:59 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	return (i < 0) ? -i : i;
}

float	max_v(float a, float b)
{
	return (a > b ? a : b);
}
