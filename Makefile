# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: domurdoc <domurdoc@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 03:50:26 by domurdoc          #+#    #+#              #
#    Updated: 2020/01/14 17:09:55 by jgroleo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -O3

SRC_NAME = ft_check_next.c ft_find_size.c ft_flag_hash.c ft_flagminus.c ft_itoas.c ft_lib_1.c \
		   ft_lib_2.c ft_move_xx.c ft_parce.c ft_prec.c ft_prepare_str.c ft_printf.c ft_putstrs.c \
		   ft_round.c ft_str_mods.c ft_zero.c ft_extra.c

INCLUDES_NAME = ft_printf.h

#ft_printf
SRC_DIR = srcs
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_NAME))

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC_NAME:.c=.o))

INCLUDES_DIR = includes
INCLUDES = $(addprefix $(INCLUDES_DIR)/,$(INCLUDES_NAME))

#color
GREEN = \033[0;32m
RED = \033[0;31m
EOC = \033[m

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)✓ Building $(NAME)$(EOC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✗ Deletion of object files$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ Deletion of $(NAME)$(EOC)"

re: fclean all
