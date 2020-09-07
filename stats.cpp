#include "stats.h"
#include <algorithm>
#include <cmath>

Statistics::Stats Statistics::ComputeStatistics(std::vector<float>& number_set)
{
	Stats stats{};
	
	float sum = 0.0f;
	auto number = number_set.begin();
	
	while(number != number_set.end())
	{
		if (!std::isnan(*number))
		{
			sum += *(number);
			++number;
		}
		else
		{
			number = number_set.erase(number);
		}
	}
	if(sum != static_cast<float>(0))
	{
		stats.average = sum / number_set.size();

		std::sort(number_set.begin(), number_set.end());

		stats.min = number_set.front();
		stats.max = number_set.back();

		return stats;
	}		
	stats.average = stats.max = stats.min = NAN;
	return stats;
}
