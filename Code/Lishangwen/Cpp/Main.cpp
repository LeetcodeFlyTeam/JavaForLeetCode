#include <iostream>
#include "Main.h"
int main(){
	
	LeetCodeLib lib = LeetCodeLib();
	vector<int> input{ 1,3,-1,-3,5,3,6,7 };
	auto result = lib.maxSlidingWindow(input,3);
	cout << result.size();
	//numPairsDivisibleBy60Test(lib);
}


void numPairsDivisibleBy60Test(LeetCodeLib lib){
	vector<int> input{ 30,20,150,100,40 };
	auto result = lib.numPairsDivisibleBy60(input);
	cout << result << endl;
}

void checkSubarraySumTest(vector<int>& nums, int k){
}
