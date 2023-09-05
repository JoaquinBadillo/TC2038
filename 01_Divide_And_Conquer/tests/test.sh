#!/bin/bash

echo "Testing..."
../ordena.o ./data/data1.txt > ./results/test1.txt
../ordena.o ./data/data2.txt > ./results/test2.txt	
../ordena.o ./data/data3.txt > ./results/test3.txt
python3 ./main.py