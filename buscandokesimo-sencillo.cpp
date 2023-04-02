/**
 * @file buscandokesimo-sencillo.cpp
 * @author Helena Matilde Milán Jiménez
 * @brief Buscando K-Ésimo Sencillo
 * @date 2023-04-02
 * 
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

/**
 * @brief 
 * 
 * Dados un vector numérico y una posición, devuelve el elemento que se encontraría en
 * dicha posición si el vector estuviese ordenado de menor a mayor.
 * 
 * Utiliza una variación del método de selección para encontrar el elemento en la posición k
 * del hipotético vector ordenado.
 * 
 * @param v vector numérico de n elementos
 * @param k posición del vector cuyo elemento se devuelve
 * @param n número de elementos del vector. n > 0
 * @return int elemento en la posición k del vector medio ordenado
 */
int kEsimoSencillo (int v[], int k, int n)
{	
	int indice_menor, menor, aux;
	int cont = 0;  // Posición actual (número de posiciones recorridas)
	
	// Copia del vector para no modificar el original
	int * copia = new int[n];    
	for(int i = 0; i<n; i++)
		copia[i] = v[i];
	
	// Mientras que la posición actual es menor o igual que k, busca los elementos más 
	// pequeños y los coloca en orden al principio
	while (cont <= k){                 
		indice_menor = cont;           
    	menor = copia[cont];           
    	
    	// Busca el elemento más pequeño de la parte del vector que aún no ha sido ordenada
		for (int i = cont; i < n; i++)
			if (copia[i] < menor) {
				indice_menor = i;
				menor = copia[i];
			}
		
		// Intercambia las posiciones del elemento más pequeño y el elemento de la posición
		// actual  
		aux = copia[cont];
		copia[cont] = copia[indice_menor];
		copia[indice_menor] = aux;
		
		cont++;  // Incrementa la posición actual
	}
	
	delete [] copia;  // Borra la copia
	
	return copia[cont-1];  // Devuelve el elemento en la posición k del vector medio ordenado
}


int main(int argc, char * argv[])
{	
	// Comprobación del número de argumentos
	if (argc != 3)
	{
		cerr << "Formato " << argv[0] << " <num_elem> <k>" << endl;
		return -1;
	}

	// Asignación de variables a los argumentos del programa
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int elem;

	// Comprobación de la corrección de los argumentos
	if (k < 0 || k >= n || n<1)
	{
		cerr << "Error: 0 <= k < num_elem" << endl;
		return -1;
	}

	// Variables para la medición del tiempo
	clock_t tantes, tdespues;

	// Declaración del vector
	int * v = new int[n];
	assert(v);
	
	// Inicialización del vector con elementos random
	srand(time(0));
	for (int j=0; j<n; j++){
		v[j] = rand()%n;
	}

	// Valor de reloj antes de la llamada
	tantes=clock();

	// Llamada a la función para buscar el k-ésimo menor elemento
	elem = kEsimoSencillo(v, k, n);

	// Valor del reloj después de ejecución
  	tdespues=clock();

	// Impresión de los resultados por pantalla
	cout<< n << " "<< (double)(tdespues-tantes) / CLOCKS_PER_SEC <<endl;

	// Borrado del vector en memoria dinámica
	delete [] v;
	
	return 0;

}
