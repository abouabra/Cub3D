/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:28:41 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 18:43:24 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_identifier(char *line)
{
	if(!ft_strncmp("NO", line, 2)
		|| !ft_strncmp("SO", line, 2)
		|| !ft_strncmp("WE", line, 2)
		|| !ft_strncmp("EA", line, 2)
		|| !ft_strncmp("F", line, 1)
		|| !ft_strncmp("C", line, 1))
		return 1;
	return 0;
}

void	parse_data(t_vars *vars, char **map)
{
	char **data;
	char **line;
	t_info *node;
	int i;
	
	data = my_alloc(6 * sizeof(char *));
	if(!data)
		custom_exit(0);
	i= -1;
	while(map[++i])
	{
		if(map[i][0] == ' ')
			break;
		(vars->number_of_lines)++;
		if(is_identifier(map[i]))
		{
			line = ft_split(map[i], ' ');
			node = ft_new_info(line[0], line[1]);
			add_info_in_back(&vars->info_head, node);
		}
	}
}

void get_data(t_vars *vars, char *map_name)
{
	int		fd;
	char	*tmp;
	char	*str;
	
	str = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		str = ft_strjoin_gnl(str, tmp);
	}
	close(fd);
	vars->full_map = ft_split(str, '\n');
	parse_data(vars, vars->full_map);
	vars->map = vars->full_map + vars->number_of_lines;
}

int	map_check(t_vars *vars, char *map_name)
{
	get_data(vars, map_name);
	if (!vars->map)
		return (0);
	if (!map_operation(vars, map_name))
		return (0);


	// t_info *node;
	// node = vars->info_head;
	// while(node)
	// {
	// 	ft_dprintf(1,"%s: %s\n",node->id,get_info_data(vars,node->id));
	// 	node = node->next;
	// }
	// int i;
	// i= -1;
	// while(vars->map[++i])
	// 	ft_dprintf(1,"%s\n",vars->map[i]);
	return (1);
}
