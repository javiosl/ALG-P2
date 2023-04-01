echo "" >> salida.dat
a=30
for ((P=500;P<=32500;P=P+500))
do 
B=$(( $P - $a ))
 ./buscandokesimo-sencillo $P $B >> salidaSencillo.dat
done
