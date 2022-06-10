/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:57:18 by jsankari          #+#    #+#             */
/*   Updated: 2022/06/10 16:25:13 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_instructions(t_mom *mom)
{
	if (mom->instructions == 1)
	{
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 20, C_WHITE,
			"MOVE = ARROWS");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 40, C_WHITE,
			"ZOOM = A/Z || MOUSE SCROLL");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 60, C_WHITE,
			"MAX ITERATIONS = S/X");
		mlx_string_put(mom->mlx_ptr, mom->win_ptr, 10, 80, C_WHITE,
			"INSTRUCTIONS = D");
	}
}

int	fractal_number(char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(av, "julia") == 0)
		return (2);
	else if (ft_strcmp(av, "burningship") == 0)
		return (3);
	else
		return (0);
}

void	initialize_mlx(t_mom *mom, char *fractal_name)
{
	mom->mlx_ptr = mlx_init();
	if (!mom->mlx_ptr)
		exit(0);
	mom->win_ptr = mlx_new_window(mom->mlx_ptr, mom->win.wid,
			mom->win.hei, fractal_name);
	mom->img_ptr = mlx_new_image(mom->mlx_ptr, mom->win.wid, mom->win.hei);
	mom->pix_ray = (int *)mlx_get_data_addr(mom->img_ptr,
			&mom->b_p_p, &mom->size_line, &mom->endian);
}

t_mom	initialize_fractol(char **av)
{
	t_mom	mom;

	mom.win.wid = 1200;
	mom.win.hei = 1200;
	mom.fracnum = fractal_number(av[1]);
	initialize_mlx(&mom, av[1]);
	mom.loc.x = 0;
	mom.loc.y = 0;
	mom.loc.offy = 0;
	mom.loc.offx = 0;
	mom.loc.zoom = 1;
	mom.reim.minre = -1.0;
	mom.reim.maxre = 1.0;
	mom.reim.minim = -1.0;
	mom.reim.maxim = 1.0;
	mom.reim.maxit = 50;
	mom.reim.imfactor = (mom.reim.maxim - mom.reim.minim) / (mom.win.hei);
	mom.reim.refactor = (mom.reim.maxre - mom.reim.minre) / (mom.win.wid);
	mom.instructions = 1;
	return (mom);
}

int	main(int ac, char **av)
{
	t_mom	mom;

	if (ac != 2)
		errors(1);
	mom = initialize_fractol(av);
	mlx_hook(mom.win_ptr, 2, (long)1L, key_map, &mom);
	mlx_hook(mom.win_ptr, 33, 0, close_window, &mom);
	mlx_hook(mom.win_ptr, 6, 1L << 6, mouse_move, &mom);
	mlx_hook(mom.win_ptr, 4, 1L << 2, mouse_button, &mom);
	mlx_loop_hook(mom.mlx_ptr, draw_fractals, &mom);
	mlx_loop(mom.mlx_ptr);
	return (0);
}
