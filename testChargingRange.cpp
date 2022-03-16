#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "currentChargingRange.h"

TEST_CASE("detect sorted single current charging range and output the number of readings") {
  std::vector<int> chargingRange = {4, 5};
  std::map<std::string, int> rangeFrequency = {{"4-5", 2}};
  REQUIRE(inferCurrentChargingRange(chargingRange) == rangeFrequency);
}

TEST_CASE("detect sorted multiple current charging range and output the number of readings") {
  std::vector<int> chargingRange = {4, 5, 7, 8, 9};
  std::map<std::string, int> rangeFrequency = {{"4-5", 2}, {"7-9", 3}};
  REQUIRE(inferCurrentChargingRange(chargingRange) == rangeFrequency);
}

TEST_CASE("detect unsorted single current charging range and output the number of readings") {
  std::vector<int> chargingRange = {5, 4};
  std::map<std::string, int> rangeFrequency = {{"4-5", 2}};
  REQUIRE(inferCurrentChargingRange(chargingRange) == rangeFrequency);
}

TEST_CASE("detect unsorted multiple current charging range and output the number of readings") {
  std::vector<int> chargingRange = {7, 5, 8, 4, 9};
  std::map<std::string, int> rangeFrequency = {{"4-5", 2}, {"7-9", 3}};
  REQUIRE(inferCurrentChargingRange(chargingRange) == rangeFrequency);
}
