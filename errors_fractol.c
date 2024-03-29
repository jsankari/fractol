/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:01:43 by jsankari          #+#    #+#             */
/*   Updated: 2022/06/10 15:56:14 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(int errcode)
{
	if (errcode == 1)
	{
		ft_putstr_fd("Usage: ./fractol <name_of_fractal> fractals: mandelbrot, \
julia, burningship\n", 2);
	}
	exit(0);
}

int	close_window(void)
{
	exit(0);
}
