# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 17:53:03 by jsankari          #+#    #+#              #
#    Updated: 2021/01/05 21:36:55 by jsankari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main_fractol.c \
errors_fractol.c \
keys_fractol.c \
keyhook_fractol.c \

OBJ = $(SRCS:.c=.o)

LIBRARY = libft/libft.a

INCLUDE = -I /usr/local/include

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

MLXHOME = -L /usr/local/lib -lmlx -I /usr/local/X11/include -L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

MLXLINUX = -L /usr/local/lib -lmlx -I /usr/local/include/X11 -L /usr/lib/X11 -lX11 -lXext

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : 
	@$(MAKE) -C libft
	@gcc $(FLAGS) $(INCLUDE) -c $(SRCS) 
	@gcc $(FLAGS) $(LIBRARY) $(OBJ) $(MLX) -o $(NAME)
	@echo "[ Fractol executable compiled ]"

home :
	@$(MAKE) -C libft
	@gcc $(FLAGS) $(INCLUDE) -c $(SRCS) 
	@gcc $(FLAGS) $(LIBRARY) $(OBJ) $(MLXHOME) -o $(NAME)
	@echo "[ Fractol executable compiled ]"

linux :
	@$(MAKE) -C libft
	@gcc $(FLAGS) $(INCLUDE) -c $(SRCS)
	gcc $(FLAGS) $(OBJ) $(LIBRARY) $(MLXLINUX) -o $(NAME)
	@echo "[ Fractol executable compiled ]"

clean :
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)
	@echo "[ Fractol objects deleted ]"

fclean : clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)
	@echo [ Fractol executable deleted ]

re : fclean all
	@$(MAKE) re -C libft

.PHONY = all clean fclean re