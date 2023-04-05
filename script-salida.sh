echo "" >> salida.dat
a=2
for ((P=7500;P<=187500;P=P+7500))
do 
B=$(( $P - $a ))
./buscandokesimo-sencillo $P $B >> salidaSencillo.dat
./buscandokesimo-dyv $P $B >> salidaDyV.dat
done
