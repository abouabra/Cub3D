/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:52:42 by ayman             #+#    #+#             */
/*   Updated: 2023/02/19 22:27:53 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "/usr/local/include/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <time.h>
#include <stdio.h>
#include <math.h>

# define PI 3.1415926535

typedef struct t_info
{
	char			*id;
	char 			*data;
	struct t_info	*next;
}	t_info;

typedef struct t_vars
{
	void *mlx;
	void *win;
	char **map;
	char **full_map;
	int number_of_lines;
	void *imgs[2];
	int player_pos[2];
	
	float pdx;
	float pdy;
	float pa;
	
	t_info *info_head; 
}	t_vars;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum
{
	X,
	Y
};
enum
{
	Background,
	Player
};

int	map_check(t_vars *vars, char *map_name);
int	map_operation(t_vars *vars, char *map_name);
int	close_win(t_vars *vars);
int	key_movement(int keycode, t_vars *vars);
t_info	*ft_new_info(char *id, char *data);
t_info	*ft_last_info(t_info *node);
void	add_info_in_back(t_info **head, t_info *node);
void	ft_info_clear(t_info **head);
char	*get_info_data(t_vars *vars, char *id);

void draw_map(t_vars *vars);
void	move_player_up(t_vars *vars);
void	move_player_down(t_vars *vars);
void	move_player_left(t_vars *vars);
void	move_player_right(t_vars *vars);
void	rotate_player_right(t_vars *vars);
void	rotate_player_left(t_vars *vars);

void print_stuff(t_vars *vars);
int	update_frames(t_vars *vars);

#endif
