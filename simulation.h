#ifndef _ASS6_SIMULATION_H_
#define _ASS6_SIMULATION_H_

#include <string>

class Simulation {
public:
  Simulation() {}
  ~Simulation() {}
  void run(std::string);
  void writeRandomArray(std::string, int);
private:
  double* deepCopy(double*, int);
};

#endif
