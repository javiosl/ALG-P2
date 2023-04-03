/**
 * @file buscandokesimo-dyv-alt.cpp
 * @author Javier Osakar Lozano
 * @brief Buscando K-Ésimo versión Divide y Vencerás Alternativa
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
 * @brief Algoritmo de Búsqueda del K-Ésimo Elemento (Versión Divide y Vencerás Alternativa)
 * 
 * La idea es dividir el vector en dos grupos de elementos: uno que contenga
 * elementos menores que un pivote elegido aleatoriamente y otro que contenga
 * elementos mayores o iguales al pivote. 
 * 
 * Luego se compara la cantidad de elementos del grupo de menores con la posición
 * k. Si es igual, entonces el pivote es el elemento k-ésimo. Si es menor, se
 * busca el k-ésimo elemento en el grupo de menores, y si es mayor se busca el
 * k-ésimo elemento en el grupo de mayores.
 * 
 * Este proceso se repite recursivamente en cada uno de los subgrupos hasta
 * encontrar el elemento k-ésimo.
 * 
 * @param v vector de enteros sobre el que se realiza la búsqueda
 * @param k posición del elemento a buscar en el vector
 * @param n número de enteros en el vector
 * @return int valor del elemento encontrado en la posición k del vector ordenado
 */
int kEsimoDyVAlt(int v[], int k, int n){
    
    // Si el vector tiene solo un elemento, se devuelve ese elemento.
    if (n == 1) {
        return v[0];
    }
    
	// Cogemos un elemento aleatorio del vector como pivote
    int pivote;
	srand(time(0));
	pivote = rand()%n;
	
	// Dividimos el vector en dos subvectores: uno con elementos menores
	// que el pivote y otro con elementos iguales o mayores
	int * menores = new int[n];
	int * mayores = new int[n];
	int menores_tam = 0, mayores_tam = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < pivote) {
			// Al poner el "++" después de la variable, el acceso se hace
			// en la posición del vector "menores_tam" anterior al incremento
            menores[menores_tam++] = v[i];
        } else {
            menores[mayores_tam++] = v[i];
        }
    }
    
	// Si el tamaño del subvector con elementos menores es k-1, entonces el
	// pivote es el elemento k-ésimo
    if (menores_tam == k-1) {
        return pivote;
    }

	// Si el tamaño del subvector con elementos menores es mayor que k-1, en-
	// tonces el elemento k-ésimo está en el subvector de elementos menores
	else if (menores_tam > k-1) {
        return kEsimoDyVAlt(menores, menores_tam, k);
    }

	// Si el tamaño del subvector con elementos menores es menor que k-1, enton-
	// ces el elemento k-ésimo está en el subvector de elementos mayores, y se
	// busca recursivamente la posición k-ésima en ese subvector
	else {
        return kEsimoDyVAlt(mayores, mayores_tam, k-menores_tam-1);
    }
}

int main(int argc, char * argv[]){	
    
    // Comprobación del número de argumentos
	if (argc != 3){
		cerr << "Formato " << argv[0] << " <num_elem> <k>" << endl;
		return -1;
	}

	// Asignación de variables a los argumentos del programa
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int elem;

	// Comprobación de la corrección de los argumentos
	if (k < 0 || k >= n || n < 1){
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
	for (int j=0; j<n; j++){
		v[j] = rand()%n;
	}

	// Valor de reloj antes de la llamada
	tantes=clock();

	// Llamada a la función para buscar el k-ésimo menor elemento
	elem = kEsimoDyVAlt(v,k,n);

	// Valor del reloj después de ejecución
  	tdespues=clock();

	// Impresión del tamaño del problema y el tiempo tomado por pantalla
	cout << n << " "<< (double)(tdespues-tantes) / CLOCKS_PER_SEC << endl;

	// Liberación de memoria asignada para el vector
	delete [] v;
	
	return 0;

}