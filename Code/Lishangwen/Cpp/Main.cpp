#include <iostream>
#include "Main.h"
int main(){
	LeetCodeLib lib = LeetCodeLib();
	cout << lib.uniquePaths(3, 2);
	//numPairsDivisibleBy60Test(lib);
}


void numPairsDivisibleBy60Test(LeetCodeLib lib){
	vector<int> input{ 30,20,150,100,40 };
	auto result = lib.numPairsDivisibleBy60(input);
	cout << result << endl;
}

void checkSubarraySumTest(vector<int>& nums, int k){
}
