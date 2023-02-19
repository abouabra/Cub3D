/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:58:49 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 18:22:54 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_phase_1(char *map_name)
{
	char	*extention;

	extention = ft_strchr(map_name, '.');
	if (!extention)
		return (0);
	if (ft_strncmp(extention, ".cub", -1))
	{
		ft_dprintf(1, "Error\nMap does not have .cub extention\n");
		return (0);
	}
	return (1);
}

int	map_phase_2(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (!ft_strchr(" 01NSWE", vars->map[i][j]))
			{
				ft_dprintf(1, "Error\nMap Contains Other Characters\n");
				return (0);
			}
		}
	}
	return (1);
}

int	map_phase_3(t_vars *vars)
{
	int	i;
	int	j;
	//check map borders
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			
		}
	}
	return (1);
}


int	map_operation(t_vars *vars, char *map_name)
{
	if (!map_phase_1(map_name)
		|| !map_phase_2(vars))
		// || !map_phase_3(vars))
		return (0);
	return (1);
}
