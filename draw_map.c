/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:36:07 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 21:56:55 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void load_stuff(t_vars *vars)
{
	int gg;
	gg = 0;
	vars->imgs[Player] = mlx_xpm_file_to_image(vars->mlx, "Assests/player.xpm", &gg, &gg);
	vars->imgs[Background] = mlx_xpm_file_to_image(vars->mlx, "Assests/background.xpm", &gg, &gg);
	int i = -1;
	while(vars->map[++i])
	{
		int j = -1;
		while(vars->map[i][++j])
		{
			if(vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Background], j*64, i*64);
			if(vars->map[i][j] == 'N')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Player], j*64, i*64);
		}
	}
}

void draw_map(t_vars *vars)
{
	load_stuff(vars);
}