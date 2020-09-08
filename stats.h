#include <vector>

namespace Statistics {
	class Stats
	{
	public:
		float average, max, min;
		Stats() : average(0.0),max(0.0),min(0.0) {}
	};
	Stats ComputeStatistics(std::vector<float>&);
}
