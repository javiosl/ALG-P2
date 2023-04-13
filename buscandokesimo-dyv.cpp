/**
 * @file buscandokesimo-dyv.cpp
 * @author Javier Osakar Lozano
 * @brief Buscando K-Ésimo versión Divide y Vencerás
 * @date 2023-04-02
 * 
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

#include <vector>

using namespace std;

/**
 * @brief Algoritmo de Búsqueda del K-Ésimo Elemento (Versión Divide y Vencerás)
 * 
 * La idea es dividir el vector en dos grupos de elementos: uno que contenga
 * elementos menores que un pivote elegido aleatoriamente y otro que contenga
 * elementos mayores o iguales al pivote. 
 * 
 * Luego se compara la cantidad de elementos del grupo de menores con la posición
 * k. Si es igual, entonces el pivote es el elemento k-ésimo. Si es menor, se
 * busca el k-ésimo elemento en el grupo de menores, y si es mayor se busca el
 * k-ésimo elemento en el grupo de iguales o mayores.
 * 
 * Este proceso se repite recursivamente en cada uno de los subgrupos hasta
 * encontrar el elemento k-ésimo.
 * 
 * @param v vector de enteros sobre el que se realiza la búsqueda
 * @param k posición del elemento a buscar en el vector
 * @return int valor del elemento encontrado en la posición k del vector ordenado
 */
int kEsimoDyV(vector<int> &v, int k){
	
	// Si el vector tiene solo un elemento, se devuelve ese elemento.
	if(v.size() == 1){
        return v[0];
    }

	/*
	cout << "Vector dentro de la funcion: " << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	*/

	// Cogemos un elemento aleatorio del vector como pivote
	srand(time(0));
    int pivote_indice = rand()%v.size();
	int pivote = v[pivote_indice];

	/*
	cout << "Indice: " << pivote_indice << endl;
	cout << "Elemento: " << pivote << endl;
	*/
	
	// Dividimos el vector en dos subvectores: uno con elementos menores
	// que el pivote y otro con elementos iguales o mayores
    vector<int> menores, mayores;
    for(int i = 0; i < v.size(); i++){
        if(i == pivote_indice){
			continue;
		}else if(v[i] < pivote){
            menores.push_back(v[i]);
        }else{
            mayores.push_back(v[i]);
        }
    }

	/*
	cout << "Vector mayores: " << endl;
	for(int i=0; i<mayores.size(); i++){
		cout << mayores[i] << " ";
	}
	cout << endl;

	cout << "Vector menores: " << endl;
	for(int i=0; i<menores.size(); i++){
		cout << menores[i] << " ";
	}
	cout << endl;
	*/

	// Escogemos el vector en el que hacer recursión dependiendo del tamaño
	// que tengan

	// Si el tamaño del subvector con elementos menores es k-1, entonces el
	// pivote es el elemento k-ésimo
    if(menores.size() == k-1){
        return pivote;
    }
	
	// Si el tamaño del subvector con elementos menores es mayor que k-1, en-
	// tonces el elemento k-ésimo está en el subvector de elementos menores
	else if(menores.size() > k-1){
        return kEsimoDyV(menores, k);
    }
	
	// Si el tamaño del subvector con elementos menores es menor que k-1, enton-
	// ces el elemento k-ésimo está en el subvector de elementos iguales o mayores,
	// y se busca recursivamente la posición k-ésima en ese subvector
	else{
        return kEsimoDyV(mayores, k-menores.size()-1);
    }
}

int main(int argc, char * argv[]){	
    
    // Comprobación del número de argumentos
	if(argc != 3){
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
	vector<int> v;
	
	// Inicialización del vector con elementos aleatorios
	srand(time(0));
	for (int j=0; j<n; j++){
		v.push_back(rand()%n);
	}

	/*
	cout << "El vector es: " << endl;
	for(int i=0; i<n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	*/

	// Valor de reloj antes de la llamada
	tantes=clock();

	// Llamada a la función para buscar el k-ésimo menor elemento
	elem = kEsimoDyV(v,k);

	// Valor del reloj después de ejecución
  	tdespues=clock();

	/*
	cout << "Y el k elemento menor es: " << elem << endl;
	*/

	// Impresión del tamaño del problema y el tiempo tomado por pantalla
	cout << n << " "<< (double)(tdespues-tantes) / CLOCKS_PER_SEC << endl;
	
	return 0;

}