#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

/**
   @brief Dados un vector numérico y una posición, devuelve el elemento que se encontraría en
		dicha posición si el vector estuviese ordenado de menor a mayor.

   @param v: vector numérico de n elementos.
   @param k: posición del vector cuyo elemento se devuelve. 
   @param n: número de elementos del vector. n > 0.

   Utiliza una variación del método de selección para encontrar el elemento en la posición k
   del hipotético vector ordenado.
*/
int buscarElemento (int v[], int k, int n)
{	
	int indice_menor, menor, aux;
	int cont = 0;  //posición actual (número de posiciones recorridas)
	
	//Copia del vector para no modificar el original
	int * copia = new int[n];    
	for(int i = 0; i<n; i++)
		copia[i] = v[i];
	
	//Mientras que la posición actual es menor o igual que k, busca los elementos más 
	//pequeños y los coloca en orden al principio
	while (cont <= k){                 
		indice_menor = cont;           
    	menor = copia[cont];           
    	
    	//Busca el elemento más pequeño de la parte del vector que aún no ha sido ordenada
		for (int i = cont; i < n; i++)
			if (copia[i] < menor) {
				indice_menor = i;
				menor = copia[i];
			}
		
		//Intercambia las posiciones del elemento más pequeño y el elemento de la posición
		//actual  
		aux = copia[cont];
		copia[cont] = copia[indice_menor];
		copia[indice_menor] = aux;
		
		cont++;  //incrementa la posición actual
	}
	
	delete [] copia;  //borra la copia
	
	return copia[cont-1];  //devuelve el elemento en la posición k del vector medio ordenado
}


int main(int argc, char * argv[])
{	
	//Comprobación del número de argumentos
	if (argc != 3)
	{
		cerr << "Formato " << argv[0] << " <num_elem> <pos>" << endl;
		return -1;
	}
	
	
	int n = atoi(argv[1]);
	int pos = atoi(argv[2]);
	int elem;
	
	//Comprobación de argumentos
	if (pos < 0 || pos >= n || n<1)
	{
		cerr << "Error: 0 <= pos < num_elem" << endl;
		return -1;
	}
	
	//Declaración del vector
	int * v = new int[n];
	assert(v);
	
	//Inicialización del vector con elementos random
	srand(time(0));
	for (int j=0; j<n; j++) 
		v[j] = rand()%n;
	
	//Llamada a la función para buscar el k-ésimo menor elemento
	elem = buscarElemento(v, pos, n);
	
	//Borrar el vector
	delete [] v;
	
	return 0;

}
