#!/bin/bash

echo "Testing..."

a=1

while [ $a -lt 4 ]
do
    ../ordena.o ./data/data$a.txt > ./results/test$a.txt
    a=`expr $a + 1`
done

python3 ./main.py