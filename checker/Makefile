
SRC_PATH = ./src/
SRC_NAME = *.c

HEADER = ./includes/

NAME = checker

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

all : $(NAME)

$(NAME):
	@gcc -I $(HEADER) $(SRC) -o $(NAME)

clean:
	@rm $(NAME)

re : clean all
