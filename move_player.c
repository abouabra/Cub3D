/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:23:21 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 22:32:15 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_range(t_vars *vars, int x, int y)
{
	int		i;
	int		j;
	int x_calc;
	int y_calc;
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == '1')
			{
				x_calc = x - j * 64;
				y_calc = y - i * 64;
				if (x_calc + 64 > 0 && x_calc < 64 && y_calc + 64 > 0 && y_calc < 64)
					return 1;
			}
		}
	}
	return (0);
}

void	move_player_up(t_vars *vars)
{
	vars->player_pos[Y] -= 20;
}

void	move_player_down(t_vars *vars)
{
	vars->player_pos[Y] += 20;
}

void	move_player_left(t_vars *vars)
{
	vars->player_pos[X] -= 20;

}

void	move_player_right(t_vars *vars)
{
	vars->player_pos[X] += 20;
}
