#include "LeetCodeLib.h"
#include "map"
LeetCodeLib::LeetCodeLib(){
}

LeetCodeLib::~LeetCodeLib(){
}

int LeetCodeLib::numPairsDivisibleBy60(vector<int>& time) {
	if (time.size() < 2) return 0;
	int result = 0;
	vector<int> remains(60, 0);
	for (int i:time){
		result += remains[(60 - i % 60) % 60];
		remains[i % 60]++;
	}
	return result;
}

int PreSum(vector<int>& nums, int index)
{
	if (index >= nums.size() || index < 0) return 0;
	int sum = 0;
	for (int i = 0; i <= index; i++)
		sum += nums[i];
	return sum;
}

bool LeetCodeLib::checkSubarraySum(vector<int>& nums, int k)
{
	if (nums.size() < 2) return false;
	map<int, int> cacheMap;
	cacheMap[0] = -1;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if(k!=0) sum %= k;
		if (cacheMap.count(sum) && i - cacheMap[sum] > 1) return true;
		if (!cacheMap.count(sum)) cacheMap[sum] = i;
	}
	return false;
}