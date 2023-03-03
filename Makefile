TARGET=main
HEADER=includes
SRC=./srcs/objects
LIBPATH=./libs
LIBR=$(LIBPATH)/libmystd.so
OBJS= \
	$(SRC)/my_string.o \
	$(SRC)/my_complex.o \
	$(SRC)/my_array.o \
	$(SRC)/inherit_example.o \
	$(SRC)/my_vector.o \
	$(SRC)/my_stack.o \
	$(SRC)/my_excel.o
CC=g++
FLAG=-fPIC

all: $(TARGET)

re:
	make fclean
	make all

clean:
	rm -f $(SRC)/*.o

fclean:
	make clean
	rm -f $(LIBR)

$(TARGET): $(LIBR)
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs
	$(CC) -o $@ main.cpp -L$(LIBPATH) -lmystd -I$(HEADER)

$(LIBR): $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

%.o: ../%.cpp
	$(CC) -c $(FLAG) $< -I$(HEADER) -o $@

.PHONY: re fclean clean
