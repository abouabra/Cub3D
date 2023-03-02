/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:36:07 by abouabra          #+#    #+#             */
/*   Updated: 2023/03/02 19:13:00 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>


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
	float final_dis;
	float LineH;
	int r;

	disH = 100000000;
	disV = 100000000;
	ra = vars->pa-DR*(FOV/2);
	// ra = vars->pa;
	if(ra > 2 * PI)
		ra -= 2 * PI;
	else if(ra < 0)
		ra += 2 * PI;
	rays = 0;
	r = 0;
	while(rays < FOV)
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
			render_dist = RENDER_D;
		}
		while(render_dist < RENDER_D)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
	
			mp = my*(vars->longest_line-1)+mx;
			ms = (vars->number_of_lines -1) * (vars->longest_line-1);
			if(mx >= 0 && mx < vars->longest_line && my >= 0 && my < vars->number_of_lines && vars->map[my][mx] == '1')
			{
				//hit  a wall;
				
				hx = rx;
				hy  =ry;
				disH = calc_dist(vars->player_pos[X] + 16, vars->player_pos[Y] + 16, rx, ry);
				render_dist = RENDER_D;
			}
			else
			{
				rx += xo;
				ry += yo;
				render_dist += 1;
			}
		}
		// if(rx >= 0 && rx < vars->longest_line*64 && ry >= 0 && ry < vars->number_of_lines*64)
		// 	draw_line(vars, vars->player_pos[X] + 16, vars->player_pos[Y] + 16, rx, ry,0x00FF00);




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
			rx = vars->player_pos[X];
			ry = vars->player_pos[Y];
			render_dist = RENDER_D;
		}
		while(render_dist < RENDER_D)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
	
			mp = my*(vars->longest_line-1)+mx;
			ms = (vars->number_of_lines -1) * (vars->longest_line-1);
			// dprintf(1, "2 MX: %d MY: %d  %d %d\n",mx,my,vars->number_of_lines,vars->longest_line);
			if(mx >= 0 && mx < vars->longest_line && my >= 0 && my < vars->number_of_lines && vars->map[my][mx] == '1')
			{
				//hit  a wall;
				
				vx = rx;
				vy  =ry;
				disV = calc_dist(vars->player_pos[X] + 16, vars->player_pos[Y] + 16, rx, ry);
				render_dist = RENDER_D;
			}
			else
			{
				rx += xo;
				ry += yo;
				render_dist += 1;
			}
		}
		if(disH < disV)
		{
			rx = hx;
			ry = hy;
			final_dis = disH;
			vars->wall_colors[r] = 0xaf721a;
		}
		else
		{
			rx = vx;
			ry = vy;
			final_dis = disV;
			vars->wall_colors[r] = 0x693e00;
		}
		if(rx >= 0 && rx < vars->longest_line*64 && ry >= 0 && ry < vars->number_of_lines*64)
			draw_line(vars, vars->player_pos[X] + 16, vars->player_pos[Y] + 16, rx, ry,0xFF0000);
		
		ra += DR;
		if(ra > 2 * PI)
			ra -= 2 * PI;
		else if(ra < 0)
			ra += 2 * PI;
		rays++;


	//draw 3d world
		float fish_eye;
		
		fish_eye = vars->pa - ra;
		if(fish_eye > 2 * PI)
			fish_eye -= 2 * PI;
		else if(fish_eye < 0)
			fish_eye += 2 * PI;
		final_dis = final_dis * cos(fish_eye);
		LineH = (100*(vars->number_of_lines *64))/final_dis;
		if(LineH > (vars->number_of_lines *64))
			LineH = (vars->number_of_lines *64);
		vars->store[r] = LineH;
		r++;
		// draw_line(vars, r, vars->number_of_lines * 64, r, (vars->number_of_lines * 64) + LineH, 0x00FF00);
		// if(r > (vars->longest_line) * 64)
		// 	r = 0;
	}
	r = 0;
	int i = 0;
	int j = 0;
	float LineO;
	
	while(r < FOV)
	{
		j = 0;
		while(j < PIXEL_WIDTH)
		{
			LineO = (vars->number_of_lines *64)/2 - vars->store[r]/2;
			draw_line(vars, i+j, (vars->number_of_lines * 64)+LineO, i+j, (vars->number_of_lines * 64) + vars->store[r] + LineO, vars->wall_colors[r]);
			j++;
		}
		i+= PIXEL_WIDTH;
		r++;
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
}

void draw_map(t_vars *vars)
{
	int gg;
	gg = 0;
	vars->imgs[Player] = mlx_xpm_file_to_image(vars->mlx, "Assests/player.xpm", &gg, &gg);
	vars->imgs[Background] = mlx_xpm_file_to_image(vars->mlx, "Assests/background.xpm", &gg, &gg);
	print_stuff(vars);
}