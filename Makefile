
SRC_PATH = ./src/
SRC_NAME = *.c

HEADER = ./includes/

NAME = push_swap

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

all : $(NAME)

$(NAME):
	@gcc -I $(HEADER) $(SRC) -o $(NAME)

clean:
	@rm $(NAME)

re : clean all
