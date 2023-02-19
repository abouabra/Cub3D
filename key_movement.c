/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:31:17 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 16:34:30 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/get_next_line.h"

int	close_win(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	custom_exit(0);
	return 0;
}

int	key_movement(int keycode, t_vars *vars)
{
	if (keycode == 13)
	{
		// move_player_up(vars);
	}
	if (keycode == 0)
	{
		// move_player_left(vars);
	}
	if (keycode == 1)
	{
		// move_player_down(vars);
	}
	if (keycode == 2)
	{
		// move_player_right(vars);
	}
	if (keycode == 53)
		close_win(vars);
	return (0);
}
