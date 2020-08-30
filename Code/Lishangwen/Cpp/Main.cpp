#include <iostream>
#include "Main.h"
int main(){
	
	LeetCodeLib lib = LeetCodeLib();
	//vector<int> input{ 1,3,-1,-3,5,3,6,7 };
	/*
	3
		[[1, 2], [2, 3], [3, 1]]
	*/
	ListNode* head = &ListNode(1);
	ListNode* cur = head;
	cur->next = &ListNode(2);
	cur = cur->next;
	cur->next = &ListNode(3);
	lib.myListNodeHead = head;
	auto result1 = lib.getRandom();
	auto result = lib.isSubsequence("abc", "ahbgdc");
	cout << result1;
	//numPairsDivisibleBy60Test(lib);
}


void numPairsDivisibleBy60Test(LeetCodeLib lib){
	vector<int> input{ 30,20,150,100,40 };
	auto result = lib.numPairsDivisibleBy60(input);
	cout << result << endl;
}

void checkSubarraySumTest(vector<int>& nums, int k){
}
