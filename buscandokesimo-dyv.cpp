/**
 * @file buscandokesimo-dyv.cpp
 * @author Javier Osakar Lozano
 * @brief Algoritmo Búsqueda del K-Ésimo (DyV)
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
#include <vector>

using namespace std;

int k_esimo_dyv(vector<int>& v, int k) {
    
    if (v.size() == 1) {
        return v[0];
    }
    
    int pivote = v[0];
    vector<int> menores, mayores;
    
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < pivote) {
            menores.push_back(v[i]);
        } else {
            mayores.push_back(v[i]);
        }
    }
    
    if (menores.size() == k-1) {
        return pivote;
    } else if (menores.size() > k-1) {
        return k_esimo_dyv(menores, k);
    } else {
        return k_esimo_dyv(mayores, k-menores.size()-1);
    }
}

int main() {
    
    vector<int> v = {8, 2, 5, 1, 7, 4};
    int k = 3;
    
    // Usamos el algoritmo dyv
    int k_esimo = k_esimo_dyv(v, k);
    
    cout << "El elemento k-esimo (dyv) es: " << k_esimo << endl;
    
    return 0;
}