#include <sensors/sampler.hpp>
#include <string>
#include <fstream>
#include <istream>
#include <iostream>
#include <sstream>


class line : public std::string {};
std::istream &operator>>(std::istream &is, line &l);
std::istream &operator>>(std::istream &is, line &l) {
    std::getline(is, l);
    return is;
}

Sampler::Sampler(std::string in_file_name) {
  in_file = std::ifstream();
  in_file.open(in_file_name);
}
 
bool Sampler::is_available() {
  return in_file.is_open();
}

bool Sampler::read(std::string &dst) {
   std::getline(in_file, dst);
   return !!in_file;
}

