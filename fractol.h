/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:12:51 by jsankari          #+#    #+#             */
/*   Updated: 2021/01/26 14:33:01 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "defines_fractol.h"
# include "libft/libft.h"

typedef struct		s_loc
{
	int				x;
	int				y;
	double			offx;
	double			offy;
	double			zoom;
}					t_loc;

typedef struct		s_reim
{
	double			refactor;
	double			imfactor;
	double			minre;
	double			maxre;
	double			minim;
	double			maxim;
	int				maxit;
}					t_reim;

typedef struct		s_win
{
	int				wid;
	int				hei;
}					t_win;

typedef struct		s_mom
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*fracnam;
	int				fracnum;
	int				*pix_ray;
	int				b_p_p;
	int				size_line;
	int				endian;
	int				instructions;
	int				mpx;
	int				mpy;
	t_win			win;
	t_loc			loc;
	t_reim			reim;
}					t_mom;

void				errors(int errcode);
int					close_window(void);
int					key_map(int key, t_mom *mom);
int					mouse_move(int x, int y, t_mom *mom);
int					mouse_button(int button, int x, int y, t_mom *mom);
int					key_hook(t_mom *mom);

#endif
