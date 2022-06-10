/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_fractol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:10:36 by jsankari          #+#    #+#             */
/*   Updated: 2022/06/10 15:56:55 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_mom *mom)
{
	int	i;

	i = 0;
	while (mom->loc.y < mom->win.hei)
	{
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			mom->reim.z_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * \
mom->reim.imfactor * mom->loc.zoom;
			mom->reim.z_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * \
mom->reim.refactor * mom->loc.zoom;
			i = iterations(mom);
			mom->reim.c_re = mom->reim.minre + mom->mpx * mom->reim.refactor;
			mom->reim.c_im = mom->reim.maxim - mom->mpy * mom->reim.imfactor;
			ft_color(i, mom);
			mom->loc.x++;
		}
		mom->loc.y++;
	}
}

void	mandelbrot(t_mom *mom)
{
	int		i;

	i = 0;
	while (mom->loc.y < mom->win.hei)
	{
		mom->reim.c_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * \
mom->reim.imfactor * mom->loc.zoom;
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			mom->reim.c_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * \
mom->reim.refactor * mom->loc.zoom;
			mom->reim.z_re = mom->reim.c_re;
			mom->reim.z_im = mom->reim.c_im;
			i = iterations(mom);
			ft_color(i, mom);
			mom->loc.x++;
		}
		mom->loc.y++;
	}
}

void	burningship(t_mom *mom)
{
	int		i;

	i = 0;
	while (mom->loc.y < mom->win.hei)
	{
		mom->reim.c_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * \
mom->reim.imfactor * mom->loc.zoom;
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			mom->reim.c_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * \
mom->reim.refactor * mom->loc.zoom;
			mom->reim.z_re = mom->reim.c_re;
			mom->reim.z_im = mom->reim.c_im;
			i = iterations(mom);
			ft_color(i, mom);
			mom->loc.x++;
		}
		mom->loc.y++;
	}
}

int	draw_fractals(t_mom *mom)
{
	mom->loc.y = 0;
	mom->loc.x = 0;
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	if (mom->fracnum == 1)
		mandelbrot(mom);
	else if (mom->fracnum == 2)
		julia(mom);
	else if (mom->fracnum == 3)
		burningship(mom);
	else
		errors(1);
	mlx_put_image_to_window(mom->mlx_ptr, mom->win_ptr, mom->img_ptr, 0, 0);
	if (mom->instructions == 1)
		key_instructions(mom);
	return (0);
}
