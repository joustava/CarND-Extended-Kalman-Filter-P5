#include <fstream>
//#include <istream>
// #include <iostream>
// #include <sstream>


class SensorBus {
  private:
  bool is_ready;
  std::ifstream in_file;

  public:
  SensorBus(std::string in_file_name = "./tests/utils/fixture.txt");
  bool is_available();
  bool read(std::string &package);
};
