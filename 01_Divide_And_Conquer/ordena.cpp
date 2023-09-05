/* 
 Driver Program
 
 Uses the reader, mergesort and quicksort implementations 
 to sort a list of integers and print the results to the
 console.

 Author: Prof. Víctor Manuel de la Cueva Hernández 
 Modified by: Joaquín Badillo A0102634
 Last update: 04/Sept/2023
*/

#include "lib/mergesort.hpp"
#include "lib/quicksort.hpp"
#include "lib/reader.hpp"

using namespace std;

// Driver Program
int main(int argc, char const *argv[]) {
  // Check if data file is passed as argument, otherwise use default ("datos.txt")
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
