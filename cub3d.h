/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:52:42 by ayman             #+#    #+#             */
/*   Updated: 2023/03/04 18:13:16 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "/usr/local/include/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>

# define RENDER_D 5120
# define FOV 120
# define PIXEL_WIDTH 15
# define DR 0.011
// # define DR 0.0174533
# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * (PI / 2)

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct t_info
{
	char			*id;
	int r;
	int g;
	int b;
	struct t_info	*next;
}					t_info;

typedef struct t_vars
{
	void			*mlx;
	void			*win;
	char			**map;
	char			**full_map;
	int				number_of_lines;
	int				longest_line;
	void			*imgs[2];
	int				player_pos[2];	
	float			pdx;
	float			pdy;
	float			pa;
	float			store[FOV];
	float			wall_colors[FOV];

	t_data			*main_img;
	
	t_info			*info_head;
}					t_vars;

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

void draw_line(t_vars *vars, int px, int py, int ex, int ey, int color);

int					map_check(t_vars *vars, char *map_name);
int					map_operation(t_vars *vars, char *map_name);
int					close_win(t_vars *vars);
int					key_movement(int keycode, t_vars *vars);
t_info				*ft_new_info(char *id, char *data, int arg);
t_info				*ft_last_info(t_info *node);
void				add_info_in_back(t_info **head, t_info *node);
void				ft_info_clear(t_info **head);
t_info				*get_info_data(t_vars *vars, char *id);

void				draw_map(t_vars *vars);
void				move_player_up(t_vars *vars);
void				move_player_down(t_vars *vars);
void				move_player_left(t_vars *vars);
void				move_player_right(t_vars *vars);
void				rotate_player_right(t_vars *vars);
void				rotate_player_left(t_vars *vars);

void				print_stuff(t_vars *vars);
int					update_frames(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void shoot_ray(t_vars *vars);
int	argb(int a, int r, int g, int b);
int get_floor_color(t_vars *vars);
int get_celling_color(t_vars *vars);

#endif
