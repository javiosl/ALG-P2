#!/bin/bash

# Compilamos los dos algoritmos con optimización "-O3"
g++ -O3 -o buscandokesimo-sencillo buscandokesimo-sencillo.cpp
g++ -O3 -o buscandokesimo-dyv buscandokesimo-dyv.cpp

# Ejecutamos ambos algoritmos con tamaños de 7500 a 187500 con un incremento de 7500
# pero siempre usando k=tamaño-2 (peor caso posible para ambos algoritmos)
a=2
for ((P=7500;P<=187500;P=P+7500))
do
B=$(( $P - $a ))
./buscandokesimo-sencillo $P $B >> ./salidas/salida-sencillo.dat
./buscandokesimo-dyv $P $B >> ./salidas/salida-dyv.dat
done

# Ejecutamos ahora solo el algoritmo DyV con tamaños de 75000 a 1875000 con un
# incremento de 75000 para percibir un cambio en el tiempo de ejecución
for ((P=7500000;P<=187500000;P=P+1500000))
do
B=$(( $P - $a ))
./buscandokesimo-dyv $P $B >> ./salidas/salida-dyv-alt.dat
done