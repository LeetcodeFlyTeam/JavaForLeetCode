#pragma once
#include "vector"
#include<algorithm>
#include <iostream>
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
	int uniquePaths(int m, int n);
	int findJudge(int N, vector<vector<int>>& trust);
	int findJudgeArrayCache(int N, vector<vector<int>>& trust);
	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level);
	bool isSymmetric(TreeNode* root);
};