#include <vector>
#include "reader.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"

using namespace std;

int main(){
    vector<int> datos, datosOrdenados;
    datos = leeDatos("datos.txt");
    imprimeDatos(datos);

    datosOrdenados = mergeSort(datos);
    imprimeDatos(datosOrdenados);
    
    datosOrdenados = quickSort(datos);
    imprimeDatos(datosOrdenados);
    return 0;
}