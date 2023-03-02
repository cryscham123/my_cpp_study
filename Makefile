HEADER=includes
SRC=./srcs/objects
LIBR=libmystd.so
OBJS= $(SRC)/my_string.o \
	  $(SRC)/my_complex.o \
	  $(SRC)/my_array.o \
	  $(SRC)/inherit_example.o \
	  $(SRC)/my_vector.o \
	  $(SRC)/my_stack.o \
	  $(SRC)/my_excel.o
CC=g++
FLAG=-fPIC

all: $(LIBR)

re:
	make fclean
	make all

clean:
	rm -f $(SRC)/*.o

fclean:
	make clean
	rm -f $(LIBR)

$(LIBR): $(OBJS)
	$(CC) -shared -o $(LIBR) $(OBJS)

%.o: ../%.cpp
	$(CC) -c $(FLAG) $< -I$(HEADER) -o $@

.PHONY: re fclean clean
