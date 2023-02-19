/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_list_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:25:11 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/19 17:42:44 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*ft_new_info(char *id, char *data)
{
	t_info	*node;
	int		x;
	int		y;

	x = 0;
	y = 0;
	node = my_alloc(sizeof(t_info));
	if (!node)
		return (0);
	node->id = id;
	node->data = data;
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

char	*get_info_data(t_vars *vars, char *id)
{
	t_info	*node;

	node = vars->info_head;
	while (node)
	{
		if(!ft_strncmp(node->id, id, -1))
			return node->data;
		node = node->next;
	}
	return (NULL);
}
