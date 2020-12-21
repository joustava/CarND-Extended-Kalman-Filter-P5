#include <modern/lib.hpp>

#include <fmt/format.h>

#include <iostream>
#include <vector>
#include <tuple>

int main(int argc, char* argv[]) {
  int number;

  if(!usage(argc, argv)) exit(1);

  number = std::strtol(argv[1], NULL, 10);
  
  example(number);
  
  return(0);
}