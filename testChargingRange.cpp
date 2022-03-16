#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "currentChargingRange.h"

TEST_CASE("detect sorted single current charging range and output the number of readings") {
  std::vector<int> chargingRange = {4, 5};
  std::map<std::string, int> rangeFrequency = {{"4-5", 2}};
  REQUIRE(inferCurrentChargingRange(chargingRange) == rangeFrequency);
}

TEST_CASE("detect sorted multiple current charging range and output the number of readings") {
  std::vector<int> chargingRange = {4, 5, 6, 7,8};
  std::map<std::string, int> rangeFrequency = {{"4-5", 2}, {"6-8", 3}};
  REQUIRE(inferCurrentChargingRange(chargingRange) == rangeFrequency);
}
