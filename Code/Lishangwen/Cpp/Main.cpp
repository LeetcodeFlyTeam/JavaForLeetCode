#include <iostream>
#include "Main.h"

constexpr int TestFun(int a)
{
	if (a > 0)
		a = a + 1;
	return a;
}
int main(){
	int val = 10;
	cout << TestFun(val);
	/*
	LeetCodeLib lib = LeetCodeLib();

	//vector<int> input{ 1,3,-1,-3,5,3,6,7 };
	/*
	3
		[[1, 2], [2, 3], [3, 1]]
<<<<<<< HEAD
	
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
	*/
	//ListNode* head =new ListNode(1);
	//genListNode(head, 2);
	//lib.reorderList(head);
	vector<int> input{5,3,4,5};
    auto result = lib.stoneGame(input);
	cout << "OK"<<endl;
	//numPairsDivisibleBy60Test(lib);
}


void numPairsDivisibleBy60Test(LeetCodeLib lib){
	vector<int> input{ 30,20,150,100,40 };
	auto result = lib.numPairsDivisibleBy60(input);
	cout << result << endl;
}

void checkSubarraySumTest(vector<int>& nums, int k){
}

void genListNode(ListNode*head,int len)
{
	ListNode* ptr = head;
	for (int i = 2; i <= len; ++i) {
		ListNode* pNewNode = new ListNode(i);
		ptr->next = pNewNode;
		ptr = pNewNode;
	}
}
