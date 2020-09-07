#include "stats.h"
#include <algorithm>
#include <cmath>

Statistics::Stats Statistics::ComputeStatistics(std::vector<float>& number_set)
{
	Stats stats{};
	if(!number_set.empty())
	{
		float sum = 0;

		for(auto number: number_set)
		{
			sum += number;		
		}
		stats.average = sum / number_set.size();

		std::sort(number_set.begin(), number_set.end());

		stats.min = number_set.front();
		stats.max = number_set.back();

		return stats;		
	}
	stats.average = stats.max = stats.min = NAN;
	return stats;
}
