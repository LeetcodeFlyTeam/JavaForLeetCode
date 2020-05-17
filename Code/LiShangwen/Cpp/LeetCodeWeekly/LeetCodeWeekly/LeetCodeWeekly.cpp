// LeetCodeWeekly.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "LeetCodeWeekly.h"
using namespace std;
int main()
{
    LeetCodeLib lib = LeetCodeLib();
    numPairsDivisibleBy60Test(lib);
}


void numPairsDivisibleBy60Test(LeetCodeLib lib)
{
    vector<int> input{ 30,20,150,100,40 };
    auto result = lib.numPairsDivisibleBy60(input);
    cout << result<<endl;
}

void checkSubarraySumTest(vector<int>& nums, int k)
{

}