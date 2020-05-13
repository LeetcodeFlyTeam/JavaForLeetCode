#include "LeetCodeLib.h"
LeetCodeLib::LeetCodeLib(){
}

LeetCodeLib::~LeetCodeLib(){
}

int LeetCodeLib::numPairsDivisibleBy60(vector<int>& time) {
	if (time.size() < 2) return 0;
	int result = 0;
	vector<int> remains(60, 0);
	for (int i:time)
	{
		result += remains[(60 - i % 60) % 60];
		remains[i % 60]++;
	}
	return result;
}