#include <sensors/bus.hpp>
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

SensorBus::SensorBus(std::string in_file_name) {
  in_file = std::ifstream();
  in_file.open(in_file_name);
}
 
bool SensorBus::is_available() {
  return in_file.is_open();
}

bool SensorBus::read(std::string &dst) {
   std::getline(in_file, dst);
   return !!in_file;
}

