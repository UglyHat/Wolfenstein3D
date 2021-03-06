/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 05:46:19 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/23 06:00:30 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "sys/time.h"
# include "libft.h"
# include "key_codes_macos.h"
# include "events.h"
# include <pthread.h>
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>

# define WIDTH 1600
# define HEIGHT 1200

typedef struct		s_img
{
	void			*img0;
	void			*img1;
	void			*img2;
	void			*img3;
	void			*img4;
	void			*img5;
	void			*img6;
	void			*img7;
}					t_img;

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plan;
	double			speed_turn;
	double			speed_move;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
}					t_player;

typedef struct		s_ray
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_ixy	map;
	struct s_dxy	side;
	struct s_dxy	delta;
	struct s_ixy	step;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*mlxwhite;
	void			*win;
	void			*img;
	void			*white;
	void			*yellow;
	char			*pxl;
	char			*pxlwhite;
	char			*pxlyellow;
	int				*addrpxl;
	int				*addrwhite;
	int				*addryellow;
	int				fps;
	int				bpp;
	int				s_line;
	int				ed;
	clock_t			next_frame;
	char			*last_input0;
	char			*last_input1;
	char			*last_input2;
	char			*last_input3;
	int				*stockdist;
}					t_mlx;

typedef struct		s_env
{
	struct s_img	image;
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				**map;
	int				map_width;
	int				map_height;
	int				i;
	int				x1;
	int				x2;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	unsigned int	color_ground;
	int				start_x;
	int				start_y;
	time_t			oldtime;
	unsigned int	time;
	float			rainrate;
	int				brightness;
}					t_env;

t_env				*init_env(void);
int					ft_loop_hook(t_env *e);
int					open_file(t_env *e, char *f);
int					ft_key_release(int k, t_env *e);
int					ft_key_move(int k, t_env *e);
void				ft_cal_ray_dist(t_env *e);
void				ft_rain(t_env *e);
void				init_thunderyellow(t_env *e);
void				init_thunder(t_env *e);
void				ft_pixel(t_env *e, int x, int y, unsigned int c);
void				draw_line(t_env *e, int x, int start, int end);
void				raycasting(t_env *e);
void				move_left(t_env *e);
void				move_right(t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_jump(t_env *e);
void				ft_rainprocess(t_env *e, int x);
void				ft_init_colors(t_env *e);
void				ft_print_weather(t_env *e);
void				ft_print_position(t_env *e);
void				ft_manage_threads(t_env *e);
void				error_map(void);
void				error_arg(void);
void				error_malloc(void);
#endif
