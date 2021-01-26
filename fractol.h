/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:12:51 by jsankari          #+#    #+#             */
/*   Updated: 2021/01/26 23:29:20 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
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
	double			c_re;
	double			c_im;
	double			z_re;
	double			z_im;
	double			z_re2;
	double			z_im2;
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
	int				fracnum;
	int				*pix_ray;
	int				b_p_p;
	int				size_line;
	int				endian;
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
int					draw_fractals(t_mom *mom);
void				calculate_z(t_mom *mom);
int					iterations(t_mom *mom);
void				ft_color(double i, t_mom *mom);

#endif
