/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:10:36 by jsankari          #+#    #+#             */
/*   Updated: 2021/01/24 11:45:10 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

/*
int		key_hook(t_mom *mom)
{
	int loc;
	int y;
	int x;

	loc = 0;
	y = 0;
	x = 0;
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	while (x * y < mom->win.wid * mom->win.hei)
	{
		if (x == 1200)
		{
			y++;
			x = 0;
		}
		mom->pix_ray[y * mom->win.wid + x] = C_BLUE;
		x++;
		loc++;
	}
	if (mom->win.hei == 1234)
		exit(0);
	mlx_put_image_to_window(mom->mlx_ptr, mom->win_ptr, mom->img_ptr, 0, 0);
	return(0);
}*/

void	ft_color(int n, t_mom *mom)
{
	if (n >= 0 && n <= 9)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_PURPLE;
	if (n >= 10 && n <= 19)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_INDIGO;
	if (n >= 20 && n <= 29)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BLUE;
	if (n >= 30 && n <= 39)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_GREEN;
	if (n >= 40 && n <= 49)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_LIME;
	if (n >= 50 && n <= 59)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_YELLOW;
	if (n >= 60 && n <= 69)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_ORANGE;
	if (n >= 70 && n <= 79)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_RED;
	if (n >= 80 && n <= 89)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BURGUNDY;
	if (n >= 90 && n <= 100)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BLOOD;
}

void	julia(t_mom *mom)
{
	int n = 0;
	int maxit = 100;
	double c_re;
	double c_im;
	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;

	mom->reim.imfactor = (mom->reim.maxim - mom->reim.minim) / (mom->win.hei);
	mom->reim.refactor = (mom->reim.maxre - mom->reim.minre) / (mom->win.wid);
	mom->loc.y = 0;
	mom->loc.x = 0;
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	while(mom->loc.y < mom->win.hei)
	{
		mom->loc.x = 0;
		while(mom->loc.x < mom->win.wid)
		{
			Z_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
			Z_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			c_re = mom->reim.minre + mom->mpx * mom->reim.refactor;
			c_im = mom->reim.maxim - mom->mpy * mom->reim.imfactor;
			n = 0;
			while(n < maxit)
			{
				Z_re2 = Z_re * Z_re;
				Z_im2 = Z_im * Z_im;
				Z_im = 2 * Z_re * Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
				if(Z_re2 + Z_im2 > 4)
				{
					ft_color(n, mom);
					break;
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
	int n = 0;
	int maxit = 100;
	double c_re;
	double c_im;
	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;

	mom->reim.imfactor = (mom->reim.maxim - mom->reim.minim) / (mom->win.hei);
	mom->reim.refactor = (mom->reim.maxre - mom->reim.minre) / (mom->win.wid);
	mom->loc.y = 0;
	mom->loc.x = 0;
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	while(mom->loc.y < mom->win.hei)
	{
		c_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
		mom->loc.x = 0;
		while(mom->loc.x < mom->win.wid)
		{
			c_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			Z_re = c_re;
			Z_im = c_im;
			n = 0;
			while(n < maxit)
			{
				Z_re2 = Z_re * Z_re;
				Z_im2 = Z_im * Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					ft_color(n, mom);
					break;
				}
				Z_im = 2 * Z_re * Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
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
	int n = 0;
	int maxit = 100;
	double c_re;
	double c_im;
	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;

	mom->reim.imfactor = (mom->reim.maxim - mom->reim.minim) / (mom->win.hei);
	mom->reim.refactor = (mom->reim.maxre - mom->reim.minre) / (mom->win.wid);
	mom->loc.y = 0;
	mom->loc.x = 0;
	ft_memset(mom->pix_ray, 0, (mom->win.hei * mom->win.wid * 4));
	while(mom->loc.y < mom->win.hei)
	{
		c_im = mom->reim.maxim - (mom->loc.y + mom->loc.offy) * mom->reim.imfactor * mom->loc.zoom;
		mom->loc.x = 0;
		while(mom->loc.x < mom->win.wid)
		{
			c_re = mom->reim.minre + (mom->loc.x + mom->loc.offx) * mom->reim.refactor * mom->loc.zoom;
			Z_re = c_re;
			Z_im = c_im;
			n = 0;
			while(n < maxit)
			{
				Z_re2 = Z_re * Z_re;
				Z_im2 = Z_im * Z_im;
				Z_im = fabs(2 * Z_re * Z_im) + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
				if(Z_re2 + Z_im2 > 4)
				{
					ft_color(n, mom);
					break;
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
	if (ft_strcmp(mom->fracnam, "mandelbrot") == 0)
		mandelbrot(mom);
	else if (ft_strcmp(mom->fracnam, "julia") == 0)
		julia(mom);
	else if (ft_strcmp(mom->fracnam, "burningship") == 0)
		burningship(mom);
	else
		errors(1);
	return(0);
}
