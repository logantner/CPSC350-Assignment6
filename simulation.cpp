#include "simulation.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"

void Simulation::run(std::string fileName) {
  // Open files, check if it exists
  std::ifstream fin (fileName);
  if (!fin.is_open()) {
    std::cout << "Sorry, the file could not be found." << std::endl;
    return;
  }

  // Read file into an array
  int size;
  fin >> size;
  double* data = new double[size];
  for (int i=0; i<size; ++i) {
    fin >> data[i];
  }

  // Copy the array and test runtimes for each of 4 methods

  double* dataCopy = deepCopy(data, size);
  clock_t t = clock();
  bubbleSort(dataCopy, size);
  std::cout << "Bubble sort took " << 1.0*(clock() - t)/CLOCKS_PER_SEC << " seconds.\n";

  dataCopy = deepCopy(data, size);
  t = clock();
  insertionSort(dataCopy, size);
  std::cout << "Insertion sort took " << 1.0*(clock() - t)/CLOCKS_PER_SEC << " seconds.\n";

  dataCopy = deepCopy(data, size);
  t = clock();
  quickSort(dataCopy, size);
  std::cout << "Quick sort took " << 1.0*(clock() - t)/CLOCKS_PER_SEC << " seconds.\n";

  dataCopy = deepCopy(data, size);
  t = clock();
  cocktailSort(dataCopy, size);
  std::cout << "Cocktail sort took " << 1.0*(clock() - t)/CLOCKS_PER_SEC << " seconds.\n";

  fin.close();
  delete[] data;
}

double* Simulation::deepCopy(double* data, int size) {
  // Makes a deep copy of the data array into a new array, then returns it
  double* copy = new double[size];
  for (int i=0; i<size; ++i) {
    copy[i] = data[i];
  }
  return copy;
}

void Simulation::writeRandomArray(std::string fileName, int size) {
  // Writes a file of specified name and size consisting of random doubles drawn
  // between 0 and 1
  std::ofstream fout (fileName);
  fout << size << "\n";
  double randVal;
  for (int i=0; i<size; ++i) {
    randVal = 1.0*rand()/RAND_MAX;
    fout << randVal << "\n";
  }
  fout.close();
}
