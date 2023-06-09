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
 * @brief Algoritmo de Búsqueda del K-Ésimo Elemento (Versión Sencilla)
 * 
 * Dados un vector de enteros que puede tener repetidos, desordenado, y una posición, devuelve
 * el elemento que se encontraría en dicha posición si el vector estuviese ordenado de menor
 * a mayor.
 * 
 * Utiliza una variación del algoritmo de ordenación por selección para ordenar el vector.
 * 
 * @param v vector de enteros sobre el que se realiza la búsqueda
 * @param k posición del elemento a buscar en el vector
 * @param n número de enteros en el vector
 * @return int valor del elemento encontrado en la posición k del vector ordenado
 */
int kEsimoSencillo (int v[], int k, int n)
{	
	int indice_menor, menor, aux;
	int cont = 0;  // Posición actual (número de posiciones recorridas)
	
	// Mientras que la posición actual es menor o igual que k, busca los elementos más 
	// pequeños y los coloca en orden al principio
	while (cont <= k){                 
		indice_menor = cont;           
    	menor = v[cont];           
    	
    	// Busca el elemento más pequeño de la parte del vector que aún no ha sido ordenada
		for (int i = cont; i < n; i++)
			if (v[i] < menor) {
				indice_menor = i;
				menor = v[i];
			}
		
		// Intercambia las posiciones del elemento más pequeño y el elemento de la posición
		// actual  
		aux = v[cont];
		v[cont] = v[indice_menor];
		v[indice_menor] = aux;
		
		cont++;  // Incrementa la posición actual
	}
	
	return v[cont-1];  // Devuelve el elemento en la posición k del vector medio ordenado
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
	if (k < 0 || k >= n || n < 1)
	{
		cerr << "Error: 0 <= k < num_elem" << endl;
		return -1;
	}

	// Variables para la medición del tiempo
	clock_t tantes, tdespues;

	// Declaración del vector
	int * v = new int[n];
	assert(v);
	
	// Inicialización del vector con elementos aleatorios
	srand(time(0));
	for (int j=0; j<n; j++)
	{
		v[j] = rand()%n;
	}

	// Valor de reloj antes de la llamada
	tantes=clock();

	// Llamada a la función para buscar el k-ésimo menor elemento
	elem = kEsimoSencillo(v,k,n);

	// Valor del reloj después de ejecución
  	tdespues=clock();

	// Impresión del tamaño del problema y el tiempo tomado por pantalla
	cout << n << " "<< (double)(tdespues-tantes) / CLOCKS_PER_SEC << endl;

	// Liberación de memoria asignada para el vector
	delete [] v;
	
	return 0;

}
