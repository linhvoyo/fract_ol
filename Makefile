# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/14 18:53:14 by lilam             #+#    #+#              #
#    Updated: 2018/04/14 18:53:15 by lilam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# file names
SRC = main.c keys.c
OBJ = $(SRC:.c=.o)

# directories
SRCDIR = src
OBJDIR = objs
LIBDIR = libft
MLXDIR = minilibx_macos

# files with their paths
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

# compiler
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
LIBS = -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit
HEADERS = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)

# prevent name collisions with files in the directory.
.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "[$(CC)] - $<"
	@$(CC) $(CFLAGS) $(HEADERS) $< -o $@

$(NAME): $(OBJS)
	make -C $(MLXDIR)
	make -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
