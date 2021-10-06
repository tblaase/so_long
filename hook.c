#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	if (keycode == A)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->x, vars->y);
		vars->x -= TEXTURE_WIDTH;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->x, vars->y);
	}
	if (keycode == S)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->x, vars->y);
		vars->y += TEXTURE_HEIGHT;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->x, vars->y);
	}
	if (keycode == D)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->x, vars->y);
		vars->x += TEXTURE_WIDTH;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->x, vars->y);
	}
	else if (keycode == W)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->x, vars->y);
		vars->y -= TEXTURE_HEIGHT;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->x, vars->y);
	}
	printf("You moved %d times.\n", ++vars->counter);
	// printf("keycode %d\n", keycode);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		y;
	int		x;

	y = 0;
	vars.windowsize_x = 640;
	vars.windowsize_y = 640;
	vars.counter = 0;
	vars.x = 320;
	vars.y = 320;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.windowsize_x, vars.windowsize_y, "Hello world!");
	relative_path = "./textures/ship.xpm";
	vars.player = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	relative_path = "./textures/nightsky.xpm";
	vars.background = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	while(y < vars.windowsize_y)
	{
		x = 0;
		while (x < vars.windowsize_x)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.background, x, y);
			x += TEXTURE_WIDTH;
		}
		y += TEXTURE_HEIGHT;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player, vars.x, vars.y);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
