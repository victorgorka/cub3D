/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:00:29 by vde-prad          #+#    #+#             */
/*   Updated: 2023/06/26 17:20:06 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//*********************** STANDARD LIBRARIES *********************************//
# include "./libft_plus/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>

//************************** DEFINITIONS *************************************//
# define WIDTH		1024
# define HEIGHT		512
# define PIX_SQ		32
# define MAP_WIDTH	128
# define MAP_HEIGHT 128
# define PI			3.14159265359
# define ALPHA_INC	0.1
# define MULT_DELTA	3.195
# define INFINITE	1e30
# define ROT_SPEED_LEFT		-0.1
# define ROT_SPEED_RIGHT	0.1

typedef struct s_player3d
{
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	old_dx;
	double	dir_x;
	double	dir_y;
	double	cx;
	double	px;
	double	py;
	double	old_px;
	double	ray_dx;
	double	ray_dy;
	double	sdx;
	double	sdy;
	double	ddx;
	double	ddy;
	double	pwd;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		l_height;
	int		d_start;
	int		d_end;
	int		color;
	double	wall_x;
	int		tx;
	int		ty;
	double	step;
	double	tpos;
}	t_player3d;

typedef struct s_player
{
	int		y_index;
	int		x_index;
	int		sum_y;
	int		sum_x;
	int		arr_x;
	int		arr_y;
	double	x;
	double	y;
	double	dy;
	double	dx;
	double	old_px;
	double	alpha;
}	t_player;

typedef struct s_map {
	char			**map;
	int				height;
	int				width;
	char			*n_tex;
	char			*s_tex;
	char			*w_tex;
	char			*e_tex;
	unsigned int	f_hex;
	unsigned int	c_hex;
}	t_map;

typedef struct s_init {
	char	*in_route;
	char	**in_cnt;
	int		in_fd;
	int		n_tex_fd;
	int		s_tex_fd;
	int		w_tex_fd;
	int		e_tex_fd;
	char	*f_rgb;
	char	*c_rgb;
	t_map	*map;
	int		col;
	int		row;
	int		aux_idx;
}	t_init;

typedef struct s_rc{
	mlx_t			*mlx;
	mlx_image_t		*img_bg;
	mlx_image_t		*img_world;
	mlx_texture_t	*n_tex;
	mlx_texture_t	*s_tex;
	mlx_texture_t	*w_tex;
	mlx_texture_t	*e_tex;
	mlx_texture_t	*texs[4];
	mlx_image_t		*img_p;
	mlx_image_t		*img_map;
	mlx_image_t		*img_h;
	t_player		player;
	t_player3d		p3d;
	t_map			*map;
	int				sq_size_x;
	int				sq_size_y;
	t_init			init;
}	t_rc;

//*************************** FUNCTIONS **************************************//

// PARSER
void	arg_checker(int argc, char **argv, t_init *init);
void	init_vars(t_init *init);
void	map_reader(t_init *init);
int		check_texture(t_init *init, char *str);
int		check_colors(t_init *init, char *str);
char	*get_tex_or_color(t_init *init, char *str);
int		map_builder(t_init *init, int idx);
void	map_normalizer(t_init *init, int idx);
void	map_checker(t_init *init);
void	get_colors(t_init *init);
void	check_texture_files(t_init *init);
void	free_matrix(char **arr);

// CUB3D_UTILS
void	struct_free_ft(t_init *init);
void	ft_errexit(t_init *init, char *str);
int		ft_atoi_checker(const char *str, t_init *init);
void	end_game(t_rc *data);

// WORLD
void	world_builder(t_rc *data);
void	raycast(t_rc *data);
void	put_textures(t_rc *data, int x);
void	png_to_textures(t_rc *data);
// MINIMAP
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_init(t_rc *data, t_init *init);
void	ft_print_minimap(t_rc *data);
void	ft_lateral_3d_displacement(t_rc *data, char type);
void	ft_3d_displacement(t_rc *data, char type);
void	ft_lateral_mv(t_rc *data, char type);
void	ft_is_wall(t_rc *data, double py, double px, char type);
int		is_wall(t_rc *data, double py, double px);
void	ft_rotation(mlx_key_data_t keydata, t_rc *data);
#endif
