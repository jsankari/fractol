/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:10:36 by jsankari          #+#    #+#             */
/*   Updated: 2021/01/26 20:34:05 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_color(double n, t_mom *mom)
{
	if (n < mom->reim.maxit * 0.1)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_PURPLE;
	else if (n < mom->reim.maxit * 0.2)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_INDIGO;
	else if (n < mom->reim.maxit * 0.3)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BLUE;
	else if (n < mom->reim.maxit * 0.4)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_GREEN;
	else if (n < mom->reim.maxit * 0.5)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_LIME;
	else if (n < mom->reim.maxit * 0.6)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_YELLOW;
	else if (n < mom->reim.maxit * 0.7)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_ORANGE;
	else if (n < mom->reim.maxit * 0.8)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_RED;
	else if (n < mom->reim.maxit * 0.9)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BURGUNDY;
	else if (n < mom->reim.maxit)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BLOOD;
}

void	julia(t_mom *mom)
{
	int		n;

	n = 0;
	while (mom->loc.y < mom->win.hei)
	{
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			mom->reim.z_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
			mom->reim.z_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			n = 0;
			while (n < mom->reim.maxit)
			{
				mom->reim.z_re2 = mom->reim.z_re * mom->reim.z_re;
				mom->reim.z_im2 = mom->reim.z_im * mom->reim.z_im;
				mom->reim.z_im = 2 * mom->reim.z_re * mom->reim.z_im + mom->reim.c_im;
				mom->reim.z_re = mom->reim.z_re2 - mom->reim.z_im2 + mom->reim.c_re;
				if (mom->reim.z_re2 + mom->reim.z_im2 > 4)
				{
					ft_color(n, mom);
					break ;
				}
				mom->reim.c_re = mom->reim.minre + mom->mpx * mom->reim.refactor;
				mom->reim.c_im = mom->reim.maxim - mom->mpy * mom->reim.imfactor;
				n++;
			}
			mom->loc.x++;
		}
		mom->loc.y++;
	}
}

void	mandelbrot(t_mom *mom)
{
	int		n;

	n = 0;
	while (mom->loc.y < mom->win.hei)
	{
		mom->reim.c_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			mom->reim.c_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			mom->reim.z_re = mom->reim.c_re;
			mom->reim.z_im = mom->reim.c_im;
			n = 0;
			while (n < mom->reim.maxit)
			{
				mom->reim.z_re2 = mom->reim.z_re * mom->reim.z_re;
				mom->reim.z_im2 = mom->reim.z_im * mom->reim.z_im;
				if (mom->reim.z_re2 + mom->reim.z_im2 > 4)
				{
					ft_color(n, mom);
					break ;
				}
				mom->reim.z_im = 2 * mom->reim.z_re * mom->reim.z_im + mom->reim.c_im;
				mom->reim.z_re = mom->reim.z_re2 - mom->reim.z_im2 + mom->reim.c_re;
				n++;
			}
			mom->loc.x++;
		}
		mom->loc.y++;
	}
}

void	burningship(t_mom *mom)
{
	int		n;

	n = 0;
	while (mom->loc.y < mom->win.hei)
	{
		mom->reim.c_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			mom->reim.c_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			mom->reim.z_re = mom->reim.c_re;
			mom->reim.z_im = mom->reim.c_im;
			n = 0;
			while (n < mom->reim.maxit)
			{
				mom->reim.z_re2 = mom->reim.z_re * mom->reim.z_re;
				mom->reim.z_im2 = mom->reim.z_im * mom->reim.z_im;
				if (mom->reim.z_re2 + mom->reim.z_im2 > 4)
				{
					ft_color(n, mom);
					break ;
				}
				mom->reim.z_im = fabs(2 * mom->reim.z_re * mom->reim.z_im) + mom->reim.c_im;
				mom->reim.z_re = mom->reim.z_re2 - mom->reim.z_im2 + mom->reim.c_re;
				n++;
			}
			mom->loc.x++;
		}
		mom->loc.y++;
	}
}

int		draw_fractals(t_mom *mom)
{
	mom->reim.c_re = 0;
	mom->reim.c_im = 0;
	mom->reim.z_re = 0;
	mom->reim.z_im = 0;
	mom->reim.z_re2 = 0;
	mom->reim.z_im2 = 0;
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
	return (0);
}
