/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:05:23 by abouabra          #+#    #+#             */
/*   Updated: 2023/03/04 18:22:14 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

int	update_frames(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	ft_bzero(vars->main_img, sizeof(t_data *));
	vars->main_img->img = mlx_new_image(vars->mlx, vars->longest_line*64, (vars->number_of_lines* 64)*2);
	vars->main_img->addr = mlx_get_data_addr(vars->main_img->img,
		&vars->main_img->bits_per_pixel
		,&vars->main_img->line_length, &vars->main_img->endian);
	shoot_ray(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->main_img->img, 0, 0);
	//print_stuff(vars);
	return 0;
}