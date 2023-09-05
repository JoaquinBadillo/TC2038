# Super simple makefile

all: clean build run test

build:
	@echo "\nCompiling..."
	@g++ -std=c++11 ordena.cpp -o ordena.o -Wall -Wextra -g 

run:
	@echo "\nRunning with 'datos.txt' file"
	@./ordena.o

test:
	@echo "\nTesting..."
	@./ordena.o ./tests/data/data1.txt > ./tests/results/test1.txt
	@./ordena.o ./tests/data/data2.txt > ./tests/results/test2.txt	
	@./ordena.o ./tests/data/data3.txt > ./tests/results/test3.txt
	@python3 ./tests/main.py

clean:
	@echo "Cleaning files..."
	@rm -f ./ordena.o
	@rm -f ./test/results/*.txt