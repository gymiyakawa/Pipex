# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 15:18:11 by gmiyakaw          #+#    #+#              #
#    Updated: 2023/01/18 14:12:54 by gmiyakaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:10:06 by gmiyakaw          #+#    #+#              #
#    Updated: 2022/12/20 15:35:04 by gmiyakaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		copied from Fractol, WILL NOT WORK YET

NAME 	=	pipex

OBJ	=	$(SRC:.c=.o)

LIB 	=	libft/libft.a

SRC		=	pipex.c init.c error_management.c

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

COMP	=	$(CC) $(CFLAGS) $(LIB)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
				$(MAKE) bonus -C ./libft
				$(COMP) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
	$(MAKE) fclean -C ./libft

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re:			fclean all

