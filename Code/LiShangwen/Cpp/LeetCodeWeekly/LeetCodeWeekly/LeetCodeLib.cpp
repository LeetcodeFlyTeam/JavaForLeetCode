#include "LeetCodeLib.h"
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
	for (int i = 1; i < nums.size(); i++) {
		for (int j = 0; j <= i - 1; j++) {
			if (k != 0) {
				if ((PreSum(nums, i) - PreSum(nums, j - 1)) % k == 0)
					return true;
			}
			else if ((PreSum(nums, i) - PreSum(nums, j - 1)) == 0)
				return true;
		}
	}
	return false;
}