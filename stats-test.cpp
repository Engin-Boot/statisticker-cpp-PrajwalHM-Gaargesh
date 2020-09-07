#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>

TEST_CASE("compute average, minimum and maximum for Non NaN values") {
	std::vector<float> number_set{ 1.5f, 8.9f, 3.2f, 4.5f };
    auto computedStats = Statistics::ComputeStatistics(number_set);
    float epsilon = 0.001f;
	
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
	std::vector<float> number_set{};
    auto computedStats = Statistics::ComputeStatistics(number_set);
	
	REQUIRE(std::isnan(computedStats.min) == true);
	REQUIRE(std::isnan(computedStats.max) == true);
	REQUIRE(std::isnan(computedStats.average) == true);
}

TEST_CASE("calculate average for array having NaN elements by considering non NaN values") {
	std::vector<float> number_set{ 1.5f, 8.9f,NAN, 3.2f, 4.5f,NAN};
	auto computedStats = Statistics::ComputeStatistics(number_set);

	float epsilon = 0.001f;
	REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
	REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
	REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("when all values are  NaN elements output NaN") {
	std::vector<float> number_set{ NAN,NAN,NAN };
	auto computedStats = Statistics::ComputeStatistics(number_set);

	REQUIRE(std::isnan(computedStats.min) == true);
	REQUIRE(std::isnan(computedStats.max) == true);
	REQUIRE(std::isnan(computedStats.average) == true);
}