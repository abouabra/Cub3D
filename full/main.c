/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:30:12 by abouabra          #+#    #+#             */
/*   Updated: 2023/03/04 18:28:45 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_vars *vars;
	(void)av;
	if (ac != 2)
		return (0);
	vars = my_alloc(sizeof(t_vars));
	if(!vars)
		custom_exit(0);
	if (!map_check(vars, av[1]))
		return (0);
	vars->main_img = my_alloc(sizeof(t_data));
	if(!vars->main_img)
		custom_exit(0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, FOV*PIXEL_WIDTH, vars->number_of_lines* 64, "cub3d");
	vars->main_img->img = mlx_new_image(vars->mlx, FOV*PIXEL_WIDTH, vars->number_of_lines* 64);
	vars->main_img->addr = mlx_get_data_addr(vars->main_img->img,
		&vars->main_img->bits_per_pixel
		,&vars->main_img->line_length, &vars->main_img->endian);

	// int i = -1;
	// while(++i < 50)
	// {
	// 	int j = -1;
	// 	while(++j < 50)
	// 	{
	// 		my_mlx_pixel_put(vars->main_img, j, i, 0x00FF0000);
	// 	}
	// }
	// vars->pa = P3;
	// vars->pdx = cos(vars->pa)*100;
	// vars->pdy = sin(vars->pa)*100;
	
	//draw_map(vars);
	
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_movement, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, close_win, vars);
	mlx_loop_hook(vars->mlx, update_frames, vars);
	mlx_loop(vars->mlx);
	custom_exit(0);
	return (0);
}
