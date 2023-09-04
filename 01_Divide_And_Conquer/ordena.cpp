#include "lib/mergesort.hpp"
#include "lib/quicksort.hpp"
#include "lib/reader.hpp"
#include <vector>

using namespace std;

int main() {
  vector<int> datos, datosOrdenados;
  datos = leeDatos("datos.txt");
  imprimeDatos(datos);

  datosOrdenados = mergeSort(datos);
  imprimeDatos(datosOrdenados);

  datosOrdenados = quickSort(datos);
  imprimeDatos(datosOrdenados);
  return 0;
}
