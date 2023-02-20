/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:30:12 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/20 19:40:15 by abouabra         ###   ########.fr       */
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
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->longest_line*64, vars->number_of_lines* 64, "cub3d");
	
	// vars->pa = P3;
	// vars->pdx = cos(vars->pa)*100;
	// vars->pdy = sin(vars->pa)*100;
	
	draw_map(vars);
	
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_movement, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, close_win, vars);
	mlx_loop_hook(vars->mlx, update_frames, vars);
	mlx_loop(vars->mlx);
	custom_exit(0);
	return (0);
}
