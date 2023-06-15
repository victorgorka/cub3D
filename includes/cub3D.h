#ifndef CUB3D_H
# define CUB3D_H

//*********************** STANDARD LIBRARIES *********************************//
# include "./libft_plus/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <sys/stat.h>
# include <fcntl.h>

//************************** DEFINITIONS *************************************//
# define WIDTH 1024
# define HEIGHT 512
typedef struct s_rc{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_rc;

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
	char	*input;
	int		in_fd;
	int		n_tex_fd;
	int		s_tex_fd;
	int		w_tex_fd;
	int		e_tex_fd;
	char	*f_rgb;
	char	*c_rgb;
	t_map	*map;
}	t_init;

//*************************** FUNCTIONS **************************************//
void	arg_checker(int argc, char **argv, t_init *init);


#endif
