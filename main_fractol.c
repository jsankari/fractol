/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:57:18 by jsankari          #+#    #+#             */
/*   Updated: 2021/01/24 11:02:49 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	draw_fract(t_mom *mom)
{
	int loc;
	

	loc = 0;
	while (loc < mom->win.wid * mom->win.hei)
	{
		mom->pix_ray[loc] = C_GREEN;
	}
}*/

int		close_window(void)
{
	exit(0);
}

int		mouse_move(int x, int y, t_mom *mom)
{
	mom->mpx = x;
	mom->mpy = y;
	return(0);
}

int		mouse_button(int button, int x, int y, t_mom *mom)
{
	if (button == 4)
		key_map(KEY_A, mom);
	if (button == 5)
		key_map(KEY_Z, mom);
	if (x == 3000)
		return(0);
	if (y == 3000)
		return(0);
	return (0);
}

t_mom	initialize_fractol(char **av)
{
	t_mom	mom;

	mom.win.wid = 1200;
	mom.win.hei = 1200;
	if (!(mom.mlx_ptr = mlx_init()))
		exit(0);
	mom.instructions = 1;
	mom.win_ptr = mlx_new_window(mom.mlx_ptr, mom.win.wid, mom.win.hei, av[1]);
	mom.img_ptr = mlx_new_image(mom.mlx_ptr, mom.win.wid, mom.win.hei);
	mom.pix_ray = (int*)mlx_get_data_addr(mom.img_ptr,
	&mom.b_p_p, &mom.size_line, &mom.endian);
	mom.loc.x = 0;
	mom.loc.y = 0;
	mom.loc.offy = 0;
	mom.loc.offx = 0;
	mom.loc.zoom = 1;
	mom.reim.minre = -1.0;
	mom.reim.maxre = 1.0;
	mom.reim.minim = -1.0;
	mom.reim.maxim = 1.0;
	mom.fracnam = av[1];
	//mom.reim.imfactor = (mom.reim.maxim - mom.reim.minim) / (mom.win.hei);
	//mom.reim.refactor = (mom.reim.maxre - mom.reim.minre) / (mom.win.wid);
	return (mom);
}

int		main(int ac, char **av)
{
	t_mom	mom;
	
	if (ac != 2)
		errors(1);
	mom = initialize_fractol(av);
	mlx_hook(mom.win_ptr, 2, (long)1L, key_map, &mom);
	mlx_hook(mom.win_ptr, 33, 0, close_window, &mom);
	mlx_hook(mom.win_ptr, 6, 1L<<6, mouse_move, &mom);
	mlx_hook(mom.win_ptr, 4, 1L<<2, mouse_button, &mom);
	mlx_loop_hook(mom.mlx_ptr, key_hook, &mom);
	mlx_loop(mom.mlx_ptr);
	ft_putstr(av[1]);
	return(0);
}