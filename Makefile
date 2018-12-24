CXX = g++
FLAGS = -Werror
INC_PATH = ./includes/
OBJ_PATH = ./obj/
FILE_NAME = tetripic

SRC := $(wildcard ./sources/*.cpp)
OBJS := $(SRC:.cpp=.o)


.PHONY : all clean

all: build

build: $(OBJS)
	@$(CXX) $(FLAGS) -o $@ $(OBJS) -lm
	@mkdir -p $(OBJ_PATH)
	@mv ./sources/*.o $(OBJ_PATH)
	@echo "BUILD DONE"

%.o: %.c
	@$(CXX) $(FLAGS) -o $(FILE_NAME) -I$(INC_PATH)

run_task1:
	@./build 1

run_task2:
	@./build 2

run_task3:
	@./build 3

run_task4:
	@./build 4

clean:
	@rm -rf $(OBJ_PATH) $(FILE_NAME)
	@rm build
	@rm *.bmp
	@echo "CLEAN DONE"

re: clean
	build