# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 17:53:03 by jsankari          #+#    #+#              #
#    Updated: 2022/06/10 15:51:40 by jsankari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main_fractol.c \
errors_fractol.c \
userevents_fractol.c \
fractals_fractol.c \
calculations_fractol.c \

OBJ = $(SRCS:.c=.o)

LIBRARY = libft/libft.a

MINILIBX = minilibx/libmlx.a

XFLAGS = -I /usr/local/include/X11 -L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx
	@gcc $(FLAGS) -c $(SRCS) 
	@gcc $(FLAGS) $(OBJ) $(LIBRARY) $(MINILIBX) $(XFLAGS) -o $(NAME)
	@echo "[ $(NAME) executable compiled ]"

clean :
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C minilibx
	@rm -f $(OBJ)
	@echo "[ $(NAME) objects deleted ]"

fclean : clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)
	@echo [ $(NAME) executable deleted ]

re : fclean all
	@$(MAKE) re -C libft

.PHONY = all clean fclean re