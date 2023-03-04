/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_list_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:25:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/03/04 18:12:57 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <stdio.h>

t_info	*ft_new_info(char *id, char *data, int arg)
{
	t_info	*node;
	char **arr;
	
	node = my_alloc(sizeof(t_info));
	if (!node)
		return (0);
	node->id = id;
	if(arg)
	{
		arr = ft_split(data, ',');
		node->r = ft_atoi(arr[0]);
		node->g = ft_atoi(arr[1]);;
		node->b = ft_atoi(arr[2]);;
	}
	node->next = NULL;
	return (node);
}

t_info	*ft_last_info(t_info *node)
{
	if (node)
	{
		while (node->next != NULL)
			node = node->next;
	}
	return (node);
}

void	add_info_in_back(t_info **head, t_info *node)
{
	t_info	*tmp;

	if (*head)
	{
		tmp = ft_last_info(*head);
		tmp->next = node;
	}
	else
		*head = node;
}

void	ft_info_clear(t_info **head)
{
	t_info	*tmp;

	if (head != NULL)
	{
		while (*head != NULL)
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
		}
		*head = NULL;
	}
}

t_info	*get_info_data(t_vars *vars, char *id)
{
	t_info	*node;

	node = vars->info_head;
	while (node)
	{
		if(!ft_strncmp(node->id, id, -1))
			return node;
		node = node->next;
	}
	return (NULL);
}
