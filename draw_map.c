/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:36:07 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/20 19:04:33 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

void draw_line(t_vars *vars, int px, int py, int ex, int ey, int color)
{
    int x0 = px; // x-coordinate of the starting point
    int y0 = py; // y-coordinate of the starting point
    int x1 = ex; // x-coordinate of the end point
    int y1 = ey; // y-coordinate of the end point

    int x = x0;
    int y = y0;

    int dx1 = abs(x1 - x0);
    int dy1 = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx1 - dy1;

    while (x != x1 || y != y1)
    {
        mlx_pixel_put(vars->mlx, vars->win, x, y, color);

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

float calc_dist(float px, float py, float dx, float dy)
{
	float a;
	float b;
	float c;

	a = (dx -px);
	b = (dy -py);
	c = sqrt((a*a) + (b*b));
	return c;
}

void shoot_ray(t_vars *vars)
{
	float ra;
	float ry;
	float rx;
	float xo;
	float yo;
	float aTan;
	float nTan;
	int rays;
	int render_dist;
	int mx;
	int my;
	int mp;
	int ms;
	float disH;
	float hx;
	float hy;
	float disV;
	float vx;
	float vy;
	
	disH = 100000000;
	disV = 100000000;
	ra = vars->pa-DR*30;
	if(ra > 2 * PI)
		ra -= 2 * PI;
	else if(ra < 0)
		ra += 2 * PI;
	rays = 0;
	while(rays < 1)
	{
		//check horizontal;
		render_dist = 0;
		aTan = -1/tan(ra);
		if(ra > PI)
		{
			ry = (((int)vars->player_pos[Y]>>6)<<6) - 0.0001;
			rx = (vars->player_pos[Y] - ry) * aTan + vars->player_pos[X];
			yo  = - 64;
			xo  = -yo*aTan;
		}
		if(ra < PI)
		{
			ry = (((int)vars->player_pos[Y]>>6)<<6) + 64;
			rx = (vars->player_pos[Y] - ry) * aTan + vars->player_pos[X];
			yo  =  64;
			xo  = -yo*aTan;
		}
		if(ra == PI || ra == 0)
		{
			rx = vars->player_pos[X];
			ry = vars->player_pos[Y];
			render_dist = 8;
		}
		while(render_dist < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
	
			mp = my*(vars->longest_line-1)+mx;
			ms = (vars->number_of_lines -1) * (vars->longest_line-1);
			if(mx >= 0 && mx < vars->longest_line && my >= 0 && my < vars->number_of_lines && vars->map[my][mx] == '1')
			{
				//hit  a wall;
				// dprintf(1, "MX: %d MY: %d  %d %d\n",mx,my,vars->number_of_lines,vars->longest_line);
				
				hx = rx;
				hy  =ry;
				disH = calc_dist(vars->player_pos[X] + 16, vars->player_pos[Y] + 16, rx, ry);
				render_dist = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				render_dist += 1;
			}
		}
		// draw_line(vars, vars->player_pos[X] + 16, vars->player_pos[Y] + 16, rx, ry,0x00FF00);




		//check vertical;
		render_dist = 0;
		nTan = -tan(ra);
		if(ra > P2 && ra <P3)
		{
			rx = (((int)vars->player_pos[X]>>6)<<6) - 0.0001;
			ry = (vars->player_pos[X] - rx) * nTan + vars->player_pos[Y];
			xo  = - 64;
			yo  = -xo*nTan;
		}
		if(ra < P2 || ra > P3)
		{
			rx = (((int)vars->player_pos[X]>>6)<<6) + 64;
			ry = (vars->player_pos[X] - rx) * nTan + vars->player_pos[Y];
			xo  =  64;
			yo  = -xo*nTan;
		}
		if(ra == PI || ra == 0)
		{
			rx = vars->player_pos[Y];
			ry = vars->player_pos[X];
			render_dist = 8;
		}
		while(render_dist < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
	
			mp = my*(vars->longest_line-1)+mx;
			ms = (vars->number_of_lines -1) * (vars->longest_line-1);
			if(mx >= 0 && mx < vars->longest_line && my >= 0 && my < vars->number_of_lines && vars->map[my][mx] == '1')
			{
				//hit  a wall;
				
				vx = rx;
				vy  =ry;
				disV = calc_dist(vars->player_pos[X] + 16, vars->player_pos[Y] + 16, rx, ry);
				render_dist = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				render_dist += 1;
			}
		}
		rays++;
	}
	if(disH < disV)
	{
		rx = hx;
		ry = hy;
	}
	else
	{
		rx = vx;
		ry = vy;
	}
	draw_line(vars, vars->player_pos[X] + 16, vars->player_pos[Y] + 16, rx, ry,0xFF0000);
}
void draw_zabzoub(t_vars *vars)
{
    int x0 = vars->player_pos[X] + 16;
    int y0 = vars->player_pos[Y] + 16;

    int x1 = x0 + vars->pdx;
    int y1 = y0 + vars->pdy;

	draw_line(vars,x0,y0,x1,y1,0xFF0000);
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
	draw_zabzoub(vars);
	shoot_ray(vars);
}

void draw_map(t_vars *vars)
{
	int gg;
	gg = 0;
	vars->imgs[Player] = mlx_xpm_file_to_image(vars->mlx, "Assests/player.xpm", &gg, &gg);
	vars->imgs[Background] = mlx_xpm_file_to_image(vars->mlx, "Assests/background.xpm", &gg, &gg);
	print_stuff(vars);
}