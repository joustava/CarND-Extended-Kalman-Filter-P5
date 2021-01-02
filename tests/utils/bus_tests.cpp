#include <catch2/catch.hpp>

#include <sensors/bus.hpp>
#include <sensors/sample.hpp>
#include <iostream>

SCENARIO("receiving samples", "[bus]") {
  std::vector<Sample> samples; // destination
  SensorBus bus = SensorBus();// source

  GIVEN("An existing bus is opened") {
    if (!bus.is_available()) {
      INFO("Cannot open bus: ");
    }
    
    WHEN("The bus is read") {

      std::string package;

      int i = 0;
      while(bus.read(package) && (i<=1)) {
        Sample sample;
        std::istringstream iss(package); // create input stream with read line in 'buffer'/'content'
        // data in line
        std::string sensor_type; // first token (L)
        int64_t timestamp; // second token (4.632272e-01)

        // read type first to know how to handle line
        iss >> sensor_type;

        if (sensor_type.compare("L") == 0) {  // if laser measurement
          sample.sensor_type_ = Sample::LASER;
          sample.raw_measurements_ = Eigen::VectorXd(2);
      
          // declare raw data types
          float x;
          float y;
      
          // read raw data
          iss >> x;
          iss >> y;
      
          // set raw data
          sample.raw_measurements_ << x,y;
          
          iss >> timestamp;
          sample.timestamp_ = timestamp;
          samples.push_back(sample);
        } else if (sensor_type.compare("R") == 0) {
          // Skip Radar measurements
          INFO("SENSOR TYPE R");
          continue;
        }
        ++i;

      }

      // Hold the button here
      THEN("we end up with a sample")
      {
        // Check that the power is off now.
        REQUIRE(samples.size() == 1);
      }
    }
  }
}

