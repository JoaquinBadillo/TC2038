# Super simple makefile

all: clean build run

build:
	@echo "\nCompiling..."
	@g++ -std=c++11 ordena.cpp -o ordena.o -Wall -Wextra -g 

run:
	@echo "\nRunning with 'datos.txt' file"
	@./ordena.o

clean:
	@echo "Cleaning files..."
	@rm -f ./ordena.o