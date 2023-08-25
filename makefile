CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef\
-Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations\
-Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra\
-Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op\
-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual\
-Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla\
-D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main

inout.o: inout.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

eq_solvers.o: eq_solvers.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

main.o: main.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

unit_tester.o: unit_tester.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

main: inout.o eq_solvers.o main.o
	$(CC) inout.o eq_solvers.o main.o -o square_solver $(CFLAGS)

test: eq_solvers.o unit_tester.o
	$(CC) eq_solvers.o unit_tester.o -o solve_square_tester $(CFLAGS)