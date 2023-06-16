#include "../../includes/cub3D.h"

static void	check_dup_colors(t_init *init, int opc)
{
	if (opc == 1 && init->f_rgb)
	{
		// free_ft
		ft_puterr_fd("Error\nMore than one color for Floor.\n", 2, 1);
	}
	else if (opc == 2 && init->c_rgb)
	{
		// free_ft
		ft_puterr_fd("Error\nMore than one color for Ceiling.\n", 2, 1);
	}
}

static int	check_cf(t_init *init, char *str)
{
	if (*str == 'F')
	{
		check_dup_colors(init, 1);
		init->f_rgb = get_tex_or_color(str);
		return (1);
	}
	else if (*str == 'C')
	{
		check_dup_colors(init, 2);
		init->c_rgb = get_tex_or_color(str);
		return (1);
	}
	return (0);
}

int	check_colors(t_init *init, char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp && *tmp != '\n')
	{
		while (ft_isspecialchar(*tmp))
			tmp++;
		if (check_cf(init, tmp))
			return (1);
		tmp++;
	}
	return (0);
}