/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:05:23 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 22:06:17 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_frames(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	print_stuff(vars);
	
	return 0;
}