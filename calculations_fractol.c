/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_fractol.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:59:25 by jsankari          #+#    #+#             */
/*   Updated: 2022/06/10 15:55:49 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_z(t_mom *mom)
{
	mom->reim.z_re2 = mom->reim.z_re * mom->reim.z_re;
	mom->reim.z_im2 = mom->reim.z_im * mom->reim.z_im;
	if (mom->fracnum == 1 || mom->fracnum == 2)
		mom->reim.z_im = 2 * mom->reim.z_re * mom->reim.z_im + mom->reim.c_im;
	else
		mom->reim.z_im = fabs(2 * mom->reim.z_re * mom->reim.z_im) + \
mom->reim.c_im;
	mom->reim.z_re = mom->reim.z_re2 - mom->reim.z_im2 + mom->reim.c_re;
}

int	iterations(t_mom *mom)
{
	int	i;

	i = 0;
	while (i < mom->reim.maxit)
	{
		calculate_z(mom);
		if (mom->reim.z_re2 + mom->reim.z_im2 > 4)
			break ;
		i++;
	}
	return (i);
}

void	ft_color(double i, t_mom *mom)
{
	if (i < mom->reim.maxit * 0.1)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_PURPLE;
	else if (i < mom->reim.maxit * 0.2)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_INDIGO;
	else if (i < mom->reim.maxit * 0.3)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BLUE;
	else if (i < mom->reim.maxit * 0.4)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_GREEN;
	else if (i < mom->reim.maxit * 0.5)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_LIME;
	else if (i < mom->reim.maxit * 0.6)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_YELLOW;
	else if (i < mom->reim.maxit * 0.7)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_ORANGE;
	else if (i < mom->reim.maxit * 0.8)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_RED;
	else if (i < mom->reim.maxit * 0.9)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BURGUNDY;
	else if (i < mom->reim.maxit)
		mom->pix_ray[mom->loc.y * mom->win.wid + mom->loc.x] = C_BLOOD;
}
