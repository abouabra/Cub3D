/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:36:07 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 23:04:08 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void draw_line(t_vars *vars)
{
    int x0 = vars->player_pos[X] + 16;
    int y0 = vars->player_pos[Y] + 16;

    int x1 = x0 + vars->pdx;
    int y1 = y0 + vars->pdy;

    int x = x0;
    int y = y0;

    int dx1 = abs(x1 - x0);
    int dy1 = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx1 - dy1;

    while (x != x1 || y != y1)
    {
        mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFF0000); // red pixel

        int e2 = 2 * err;
        if (e2 > -dy1)
        {
            err -= dy1;
            x += sx;
        }
        if (e2 < dx1)
        {
            err += dx1;
            y += sy;
        }
    }
}



void print_stuff(t_vars *vars)
{
	int i = -1;
	while(vars->map[++i])
	{
		int j = -1;
		while(vars->map[i][++j])
		{
			if(vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Background], j*64, i*64);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Player], vars->player_pos[X], vars->player_pos[Y]);
		}
	}
	draw_line(vars);
}

void draw_map(t_vars *vars)
{
	int gg;
	gg = 0;
	vars->imgs[Player] = mlx_xpm_file_to_image(vars->mlx, "Assests/player.xpm", &gg, &gg);
	vars->imgs[Background] = mlx_xpm_file_to_image(vars->mlx, "Assests/background.xpm", &gg, &gg);
	vars->pdx = cos(vars->pa)*100;
	vars->pdy = sin(vars->pa)*100;
	print_stuff(vars);
}