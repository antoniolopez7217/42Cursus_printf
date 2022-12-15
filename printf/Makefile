# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antlopez <antlopez@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 17:55:04 by antlopez          #+#    #+#              #
#    Updated: 2022/12/11 17:55:06 by antlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRC =		ft_printf.c ft_itoa.c ft_putf.c

OBJT =		$(SRC:.c=.o)

CFLAGS =	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):
			gcc -c $(CFLAGS) $(SRC)
			ar rcs $(NAME) $(OBJT)

clean:
			rm -f $(OBJT)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
