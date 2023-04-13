#!/bin/bash

g++ -O3 -o buscandokesimo-dyv buscandokesimo-dyv.cpp

a=2
for ((P=7500000;P<=187500000;P=P+1500000))
do
B=$(( $P - $a ))
./buscandokesimo-dyv $P $B >> ./salidas/salida-dyv-alt.dat
done