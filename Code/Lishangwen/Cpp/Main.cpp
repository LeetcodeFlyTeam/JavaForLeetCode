#include <iostream>
#include "Main.h"
int main(){
	
	LeetCodeLib lib = LeetCodeLib();
	vector<int> input{ 2,1,2,0,1 };
	int result = lib.maxProfit(input);
	//numPairsDivisibleBy60Test(lib);
}


void numPairsDivisibleBy60Test(LeetCodeLib lib){
	vector<int> input{ 30,20,150,100,40 };
	auto result = lib.numPairsDivisibleBy60(input);
	cout << result << endl;
}

void checkSubarraySumTest(vector<int>& nums, int k){
}
