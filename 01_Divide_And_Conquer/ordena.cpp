#include "lib/mergesort.hpp"
#include "lib/quicksort.hpp"
#include "lib/reader.hpp"

#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  string file;
  file = (argc > 1) ? argv[1] : "datos.txt";

  vector<int> datos, datosOrdenados;
  datos = leeDatos(file);
  imprimeDatos(datos);

  datosOrdenados = mergeSort(datos);
  imprimeDatos(datosOrdenados);

  datosOrdenados = quickSort(datos);
  imprimeDatos(datosOrdenados);
  return 0;
}
