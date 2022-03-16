#include "currentChargingRange.h"
#include <algorithm>

bool validateRange(int size, int currentPosition, int currentValue, int prevValue)
{
	return ((currentPosition == size) || ((currentValue - prevValue != 1) && (currentValue != prevValue)));
}

std::map<std::string, int> populateCurrentRange(std::vector<int> vecCurrentSamples) {
	int length = 1;
	std::map<std::string, int> mapCurrentRange;
	std::sort(vecCurrentSamples.begin(), vecCurrentSamples.end());
	for(int i = 1; i <= vecCurrentSamples.size(); i++)
	{
		if (validateRange(vecCurrentSamples.size(), i, vecCurrentSamples[i], vecCurrentSamples[i-1]))
		{
			std::string temp = std::to_string(vecCurrentSamples[i - length]) +
				    "-" + std::to_string(vecCurrentSamples[i - 1]);
			mapCurrentRange[temp] = length;
			length = 1;
			continue;
		}
		length++;
	}
	return mapCurrentRange;
}

std::map<std::string, int> inferCurrentChargingRange(std::vector<int> vecCurrentSamples) {
	std::map<std::string, int> mapCurrentRange = populateCurrentRange(vecCurrentSamples);;
	return mapCurrentRange;
}

void printOnConsole(std::map<std::string, int> mapCurrentRange) {
	std::map<std::string, int>::iterator itr;
	for(itr = mapCurrentRange.begin(); itr != mapCurrentRange.end(); itr++) {
		printf("%s, %d\n", itr->first.c_str(), itr->second);
	}
}
