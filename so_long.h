#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_vars
{
	void	*mlx;
	void	*player;
	void	*background;
	void	*win;
	int		windowsize_x;
	int		windowsize_y;
	int		x;
	int		y;
	int		counter;
}				t_vars;

#endif
