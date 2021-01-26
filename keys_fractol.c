/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:52:52 by jsankari          #+#    #+#             */
/*   Updated: 2021/01/24 10:47:54 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// REMOVE THIS BEFORE RETURN
#include <stdio.h>

int		key_map(int key, t_mom *mom)
{
	if (key == KEY_ESC)
		exit(0);
	if (mom->win.hei == 1234)
		exit(0);
	if (key == KEY_UP)
		mom->loc.offy += 8;
	if (key == KEY_DOWN)
		mom->loc.offy -= 8;
	if (key == KEY_LEFT)
		mom->loc.offx -= 8;
	if (key == KEY_RIGHT)
		mom->loc.offx += 8;
	if (key == KEY_A)
	{
		mom->loc.zoom *= 1.05;
		//mom->reim.minre *= 1.05;
		//mom->reim.maxre *= 1.05;
		//mom->reim.minim *= 1.05;
		//mom->reim.maxim *= 1.05;
	}
	if (key == KEY_Z)
	{
		mom->loc.zoom *= 0.95;
		//mom->reim.minre *= 0.95;
		//mom->reim.maxre *= 0.95;
		//mom->reim.minim *= 0.95;
		//mom->reim.maxim *= 0.95;
	}
	//printf("offx = %f\noffy = %f\n", mom->loc.offx, mom->loc.offy);
	return (0);
}
