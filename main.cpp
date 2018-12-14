#include <iostream>
#include "simulation.h"
#include "sorting.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Please include the name of your data file." << std::endl;
    return 1;
  }

  Simulation sim;
  sim.run(argv[1]);

  return 0;
}
