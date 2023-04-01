/**
 * @file buscandokesimo.cpp
 * @author Grupo 2
 * @brief Algoritmo Búsqueda del K-Ésimo
 * @date 2023-03-31
 * 
 */


// Includes Profesor
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

// Includes Añadidos
#include <algorithm>
#include <vector>

using namespace std;

int k_esimo_sencillo(vector<int>& v, int k) {
    
    // Usamos el algoritmo de ordenación por selección incluido en la biblioteca algorithm
    sort(v.begin(), v.end());
    
    return v[k-1];
}

int main(int argc, char * argv[]){
  
    //Comprobamos que los argumentos son correctos (ejecutable, num_elementos, k)
    if (argc != 3){
    cerr << "Formato: " << argv[0] << " <num_elem> <k>" << endl;
        return -1;
    }

    // Asignamos variables a los argumentos
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    // Creamos el vector
    int * v = new int[n];
    assert(v);

    // Generamos un vector que pueda tener elementos repetidos
    srand(time(0));
    for (int j=0; j<n; j++) {
        v[j] = rand()%n;
    }

    // Imprimimos el vector con sus elementos por pantalla
    cout << "El vector generado es: " << endl;
    for (int j=0; j<n; j++) {
        cout << v[j] << " ";
    }
    cout<<endl;

    // Usamos el algoritmo sencillo
    int k_esimo = k_esimo_sencillo(v, k);

    // Imprimimos el resultado por pantalla
    cout << "El elemento k-esimo es: " << k_esimo << endl;

    return 0;

}