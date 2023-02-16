NAME=main
SRC=./srcs
OBJS= $(SRC)/main.o $(SRC)/my_string.o $(SRC)/my_complex.o $(SRC)/my_array.o
CC=g++
HEADER= includes

all: $(NAME)

re:
	make fclean
	make all

clean:
	rm -f $(SRC)/*.o

fclean:
	make clean
	rm -f $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	make clean

%.o: %.cpp
	$(CC) -c $< -I$(HEADER) -o $@

.PHONY: re fclean clean