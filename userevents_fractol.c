/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userevents_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:52:52 by jsankari          #+#    #+#             */
/*   Updated: 2022/06/10 16:27:21 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instruction_switch(t_mom *mom)
{
	if (mom->instructions == 1)
		mom->instructions = 0;
	else
		mom->instructions = 1;
}

int	key_map(int key, t_mom *mom)
{
	if (key == KEY_ESC)
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
		mom->loc.zoom *= 1.05;
	if (key == KEY_Z)
		mom->loc.zoom *= 0.95;
	if (key == KEY_S && mom->reim.maxit < 500)
		mom->reim.maxit += 10;
	if (key == KEY_X && mom->reim.maxit > 20)
		mom->reim.maxit -= 10;
	if (key == KEY_D)
		instruction_switch(mom);
	return (0);
}

int	mouse_move(int x, int y, t_mom *mom)
{
	mom->mpx = x;
	mom->mpy = y;
	return (0);
}

int	mouse_button(int button, int x, int y, t_mom *mom)
{
	mom->mpx = x;
	mom->mpy = y;
	if (button == 4)
		mom->loc.zoom *= 1.05;
	if (button == 5)
		mom->loc.zoom *= 0.95;
	return (0);
}
