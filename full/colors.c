/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:52:32 by abouabra          #+#    #+#             */
/*   Updated: 2023/03/04 18:06:31 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

int get_floor_color(t_vars *vars)
{
	t_info *data;
	int color;
	
	data = get_info_data(vars, "F");
	color = argb(0, data->r, data->g, data->b);
	return color;
}

int get_celling_color(t_vars *vars)
{
	t_info *data;
	int color;
	
	data = get_info_data(vars, "C");
	color = argb(0, data->r, data->g, data->b);
	return color;
}

int	argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void draw_line(t_vars *vars, int px, int py, int ex, int ey, int color)
{
    int x0 = px;
    int y0 = py;
    int x1 = ex;
    int y1 = ey;

    int x = x0;
    int y = y0;

    int dx1 = abs(x1 - x0);
    int dy1 = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx1 - dy1;

    while (x != x1 || y != y1)
    {
		// (void) color;
		my_mlx_pixel_put(vars->main_img, x, y, color);
        // mlx_pixel_put(vars->mlx, vars->win, x, y, color);
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