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

/*
  Driver Program (Main Function)
  Tests the reader, mergesort and quicksort implementations

  Params:
  int argc: number of arguments passed to the program
  char const *argv[]: array of arguments passed to the program

  Returns:
  int: 0 if the program ran successfully. Any other value otherwise.

  Time complexity:
  O(n^2 + mn) Worst Case
  O(n log n + mn) Average QuickSort Case

  n is the number of records in the file.
  m is the longest string of digits read/printed.
  --------------------------------------------------------------
  Technically speaking m is bounded by the size of an int and it may be
  considered constant (a really big constant though). But the analysis
  is richer if we allow the word size to vary.
*/
int main(int argc, char const *argv[])
{
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
