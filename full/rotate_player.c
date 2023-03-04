/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:25:44 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/20 18:51:26 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	rotate_player_right(t_vars *vars)
{
	vars->pa -= 0.1;
	if(vars->pa < 0)
		vars->pa += 2 * PI;
	vars->pdx = cos(vars->pa)*100;
	vars->pdy = sin(vars->pa)*100;
}

void	rotate_player_left(t_vars *vars)
{
	vars->pa += 0.1;
	if(vars->pa > 2 * PI)
		vars->pa -= 2 * PI;
	vars->pdx = cos(vars->pa)*100;
	vars->pdy = sin(vars->pa)*100;
}