#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("detect the current charging range and output the number of readings") {
  std::vector<int> chargingRange = {4, 5};
  std::map<string, int> rangeFrequency = {{"4-5", 2}};
  REQUIRE(inferRange(chargingRange) == rangeFrequency);
}
