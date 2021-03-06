﻿#pragma once
#include "vector"
#include<algorithm>
#include <iostream>
#include "string.h"
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};
class LeetCodeLib
{
public:
	// 1010. 总持续时间可被 60 整除的歌曲
	int numPairsDivisibleBy60(vector<int>& time);
	bool checkSubarraySum(vector<int>& nums, int k);
	int longestUnivaluePath(TreeNode* root);
	int uniquePaths(int m, int n);
	int findJudge(int N, vector<vector<int>>& trust);
	int findJudgeArrayCache(int N, vector<vector<int>>& trust);
	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level);
	bool isSymmetric(TreeNode* root);
	int maxProfit(vector<int>& prices);
	int searchInsert(vector<int>& nums, int target);
	int rob(vector<int>& nums);
	bool canWinNim(int n);
	int myAtoi(string str);
	string convertToTitle(int n);
	vector<int> maxSlidingWindow(vector<int>& nums, int k);
	int findKthLargest(vector<int>& nums, int k);
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths);
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
	int removeDuplicates(vector<int>& nums);
	int maxSubArray(vector<int>& nums);
	int evalRPN(vector<string>& tokens);
	string longestCommonPrefix(vector<string>& strs);
	bool isSubsequence(string s, string t);
	bool search(vector<int>& nums, int target);
	ListNode* myListNodeHead;
	int getRandom();
	int countPrimes(int n);
	int trailingZeroes(int n);
	void reorderList(ListNode* head);
	bool stoneGame(vector<int>& piles);
};

class MinStack {
public:
	/** initialize your data structure here. */
	vector<int> stackData;
	int minValue=0;
	MinStack() {

	}

	void push(int x);

	void pop();

	int top();

	int getMin();
};
