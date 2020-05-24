#pragma once
#include "vector"
#include<algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class LeetCodeLib
{
public:
	// 1010. 总持续时间可被 60 整除的歌曲
	int numPairsDivisibleBy60(vector<int>& time);
	bool checkSubarraySum(vector<int>& nums, int k);
	int longestUnivaluePath(TreeNode* root);
};