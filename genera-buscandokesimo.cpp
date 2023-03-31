#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

// Generador de ejemplos para el problema de buscando el k-esimo elemento. Simplemente, para rellenar el vector de tamaño n,
// genera n enteros aleatorios entre 0 y n-1 (que forman un vector no ordenado y con elementos que pueden repetirse)

int main(int argc, char * argv[]){
  
  if (argc != 2){
    cerr << "Formato " << argv[0] << " <num_elem>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);

  int * v = new int[n];
  assert(v);

  srand(time(0));
  
  // Para generar un vector que pueda tener elementos repetidos
  for (int j=0; j<n; j++) {
    v[j] = rand()%n;
  }

  for (int j=0; j<n; j++) {cout << v[j] << " ";} cout<<endl;

}