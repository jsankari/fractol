/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:01:43 by jsankari          #+#    #+#             */
/*   Updated: 2021/01/07 17:23:35 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(int errcode)
{
	if (errcode == 1)
	{
		ft_putstr_fd("Usage: ./fractol <name_of_fractol> Fractols: Mandelbrot, Julia\n", 2);
	}
	exit(0);
}