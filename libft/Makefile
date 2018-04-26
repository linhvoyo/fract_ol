# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 09:30:55 by lilam             #+#    #+#              #
#    Updated: 2018/02/24 06:06:29 by linh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

$(NAME):
	@gcc -c -Wall -Werror -Wextra -I includes ft_*.c get_next_line.c
	@ar rc libft.a ft_*.o get_next_line.o ./includes/libft.h
	@ranlib libft.a

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean 
	@rm -rf $(NAME)

re: fclean all
