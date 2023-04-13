#!/bin/bash

g++ -O3 -o buscandokesimo-dyv buscandokesimo-dyv.cpp

a=2
for ((P=7500;P<=187500;P=P+7500))
do
B=$(( $P - $a ))
./buscandokesimo-dyv $P $B >> ./salidas/salida-dyv.dat
done