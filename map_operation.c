/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:58:49 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 20:56:11 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/ft_dprintf.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"

int	is_not_charset(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] == c)
		i++;
	if (str[i] != c && str[i])
		return (1);
	return (0);
}

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

	vars->number_of_lines = 0;
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
		(vars->number_of_lines)++;
	}
	return (1);
}



int	map_phase_3(t_vars *vars)
{
	int	i;
	int	j;
	int	z;
	int	y;
	int	y_end;
	int	y_start;
	int	x_end;
	int	x_start;

	i = -1;
	y_start = 0;
	y_end = vars->number_of_lines -1;
	while (vars->map[++i])
	{
		j = -1;
		while(vars->map[i][++j] == ' ');
		x_start = j;
		x_end = ft_strlen(vars->map[i]) -1;
		j = x_start;
		while (j <= x_end)
		{
			if ((j == x_start || j == x_end) &&  vars->map[i][j] != '1')
			{
				ft_dprintf(1, "Error\nMap is not surrounded by walls\n");
				return (0);
			}
            
			if ((i == y_start || i == y_end) && (vars->map[i][j] != '1' && vars->map[i][j] != ' '))
			{
				ft_dprintf(1, "Error\nMap is not surrounded by walls\n");
			 	return (0);
			}
			if (i > 0 && i < y_end)
			{
				char **tmp = ft_split(vars->map[i], ' ');
				z = -1;
				while(tmp[++z])
				{
					y = -1;
					while(tmp[z][++y])
					{
						if((y == 0 || y == ft_strlen(tmp[z])-1) && tmp[z][y] != '1')
						{
							ft_dprintf(1, "Error\nMap is not surrounded by walls\n");
							return (0);
						}
					}
					
				}
			}
				if (j < ft_strlen(vars->map[i]) && j > 0 &&  vars->map[i][j] != ' ' &&  vars->map[i][j] != '1' && (vars->map[i - 1][j] == ' ' || vars->map[i + 1][j] == ' ' || !vars->map[i - 1][j] || !vars->map[i + 1][j]))
				{
					ft_dprintf(1, "Error\nMap is not surrounded by walls\n");
					return (0);
				}
			j++;
		}
	}
	return (1);
}

int	map_operation(t_vars *vars, char *map_name)
{
	if (!map_phase_1(map_name)
		|| !map_phase_2(vars)
		|| !map_phase_3(vars))
		return (0);
	return (1);
}
