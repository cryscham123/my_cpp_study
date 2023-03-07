TARGET=main
INCLUDE=-Iincludes
SRC_DIR=./srcs
OBJ_DIR=./objs
LIB_DIR=./libs
LIB=$(LIB_DIR)/libmystd.so
CC=g++
CXXFLAGS=-fPIC

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))

all: $(TARGET)

.PHONY: re clean fclean

re:
	make fclean
	make all

clean:
	rm -f $(OBJ_DIR)/*.o

fclean:
	make clean
	rm -f $(LIB)

$(TARGET): $(LIB)
	export LD_LIBRARY_PATH=./libs
	$(CC) -o $@ main.cpp -L$(LIB_DIR) -lmystd $(INCLUDE)

$(LIB): $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@