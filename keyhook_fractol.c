/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:10:36 by jsankari          #+#    #+#             */
/*   Updated: 2021/01/26 14:37:54 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

/*void	ft_color(double n, t_mom *mom)
{
	if (n >= 0 && n <= 9)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_PURPLE;
	else if (n >= 10 && n <= 19)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_INDIGO;
	else if (n >= 20 && n <= 29)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BLUE;
	else if (n >= 30 && n <= 39)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_GREEN;
	else if (n >= 40 && n <= 49)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_LIME;
	else if (n >= 50 && n <= 59)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_YELLOW;
	else if (n >= 60 && n <= 69)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_ORANGE;
	else if (n >= 70 && n <= 79)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_RED;
	else if (n >= 80 && n <= 89)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BURGUNDY;
	else if (n >= 90 && n <= 100)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BLOOD;
}*/

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
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	n = 0;
	mom->reim.imfactor = (mom->reim.maxim - mom->reim.minim) / (mom->win.hei);
	mom->reim.refactor = (mom->reim.maxre - mom->reim.minre) / (mom->win.wid);
	mom->loc.y = 0;
	mom->loc.x = 0;
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	while (mom->loc.y < mom->win.hei)
	{
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			z_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
			z_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			c_re = mom->reim.minre + mom->mpx * mom->reim.refactor;
			c_im = mom->reim.maxim - mom->mpy * mom->reim.imfactor;
			n = 0;
			while (n < mom->reim.maxit)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				if (z_re2 + z_im2 > 4)
				{
					ft_color(n, mom);
					break ;
				}
				n++;
			}
			mom->loc.x++;
		}
		mom->loc.y++;
	}
	mlx_put_image_to_window(mom->mlx_ptr, mom->win_ptr, mom->img_ptr, 0, 0);
}

void	mandelbrot(t_mom *mom)
{
	int		n;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	n = 0;
	mom->reim.imfactor = (mom->reim.maxim - mom->reim.minim) / (mom->win.hei);
	mom->reim.refactor = (mom->reim.maxre - mom->reim.minre) / (mom->win.wid);
	mom->loc.y = 0;
	mom->loc.x = 0;
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	while (mom->loc.y < mom->win.hei)
	{
		c_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			c_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			z_re = c_re;
			z_im = c_im;
			n = 0;
			while (n < mom->reim.maxit)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				if (z_re2 + z_im2 > 4)
				{
					ft_color(n, mom);
					break ;
				}
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				n++;
			}
			mom->loc.x++;
		}
		mom->loc.y++;
	}
	mlx_put_image_to_window(mom->mlx_ptr, mom->win_ptr, mom->img_ptr, 0, 0);
}

void	burningship(t_mom *mom)
{
	int		n;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;

	n = 0;
	mom->reim.imfactor = (mom->reim.maxim - mom->reim.minim) / (mom->win.hei);
	mom->reim.refactor = (mom->reim.maxre - mom->reim.minre) / (mom->win.wid);
	mom->loc.y = 0;
	mom->loc.x = 0;
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	while (mom->loc.y < mom->win.hei)
	{
		c_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
		mom->loc.x = 0;
		while (mom->loc.x < mom->win.wid)
		{
			c_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			z_re = c_re;
			z_im = c_im;
			n = 0;
			while (n < mom->reim.maxit)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				z_im = fabs(2 * z_re * z_im) + c_im;
				z_re = z_re2 - z_im2 + c_re;
				if (z_re2 + z_im2 > 4)
				{
					ft_color(n, mom);
					break ;
				}
				n++;
			}
			mom->loc.x++;
		}
		mom->loc.y++;
	}
	mlx_put_image_to_window(mom->mlx_ptr, mom->win_ptr, mom->img_ptr, 0, 0);
}

int		key_hook(t_mom *mom)
{
	if (mom->fracnum == 1)
		mandelbrot(mom);
	else if (mom->fracnum == 2)
		julia(mom);
	else if (mom->fracnum == 3)
		burningship(mom);
	else
		errors(1);
	return (0);
}
