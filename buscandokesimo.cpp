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

int main() {
    
    vector<int> v = {8, 2, 5, 1, 7, 4};
    int k = 3;
    
    // Usamos el algoritmo sencillo
    int k_esimo = k_esimo_sencillo(v, k);
    
    cout << "El elemento k-esimo es: " << k_esimo << endl;
    
    return 0;
}