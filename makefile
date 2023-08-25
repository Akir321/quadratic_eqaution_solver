CXX = g++
CXX_FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef\
-Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations\
-Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra\
-Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op\
-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual\
-Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla\
-D_DEBUG -D_EJUDGE_CLIENT_SIDE

HEADERS_MAIN = inout.h square_solver.h colors.h
HEADERS_TEST = unit_tester.h square_solver.h colors.h

OBJ_MAIN = inout.o eq_solvers.o main.o
OBJ_TEST = eq_solvers.o unit_tester.o

# TEST_DIR := test
# MAIN_DIR := main

# SRC_TEST := $(wildcard $(TEST_DIR)/*.cpp)
# OBJ_TEST := $(patsubst %.cpp, %.o, $(SRC_TEST))

# separate folder for .o
# variable for .o

all: main

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

main: $(OBJ_MAIN) $(HEADERS_MAIN)
	$(CXX) $(OBJ_MAIN) -o square_solver $(CXX_FLAGS)

test: $(OBJ_TEST) $(HEADERS_TEST)
	$(CXX) $(OBJ_TEST) -o solve_square_tester $(CXX_FLAGS)

.PHONY: clean

clean:
	rm *.o