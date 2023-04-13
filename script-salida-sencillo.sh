#!/bin/bash

g++ -O3 -o buscandokesimo-sencillo buscandokesimo-sencillo.cpp

a=2
for ((P=7500;P<=187500;P=P+7500))
do
B=$(( $P - $a ))
./buscandokesimo-sencillo $P $B >> ./salidas/salida-sencillo.dat
done