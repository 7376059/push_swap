# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrady <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 21:21:02 by dgrady            #+#    #+#              #
#    Updated: 2019/11/04 21:36:26 by dgrady           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SRC_PATH = ./push_swapson/src/
PUSH_SRC_NAME = algo.c count.c functions.c functions2.c main.c stuff.c stuff2.c \
				stuff3.c validator.c
PUSH_OBJ = $(PUSH_SRC_NAME:%.c=%.o)
PUSH_NAME = push_swap
PUSH_SRC = $(addprefix $(PUSH_SRC_PATH), $(PUSH_SRC_NAME))
PUSH_HEADER = ./push_swapson/includes/


FLAGS = -Wall -Wextra ##


all : $(PUSH_NAME)

$(PUSH_NAME):
	@make re -C ./libft
	@gcc $(FLAGS) -I $(PUSH_HEADER) -c $(PUSH_SRC)
	@gcc $(FLAGS) -I $(PUSH_HEADER) $(PUSH_OBJ) -o $(PUSH_NAME) ./libft/libft.a

clean:
	@make clean -C ./libft
	@rm -f $(PUSH_OBJ)

fclean:
	@make fclean -C ./libft
	@rm -f $(PUSH_NAME)

re : clean all

