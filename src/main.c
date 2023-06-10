#include "../cub.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_FAILURE);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{

	if (keycode == 53)
		close_window(vars);
	return (0);
}

int main()
{
	t_vars	vars;
	
	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, 500, 500, "Cub3D");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	printf("works fine\n");
}
