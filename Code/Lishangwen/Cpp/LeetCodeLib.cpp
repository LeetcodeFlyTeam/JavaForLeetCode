#include "LeetCodeLib.h"
#include "map"
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


bool LeetCodeLib::checkSubarraySum(vector<int>& nums, int k){
	if (nums.size() < 2) return false;
	map<int, int> cacheMap;
	cacheMap[0] = -1;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if(k!=0) sum %= k;
		if (cacheMap.count(sum) && i - cacheMap[sum] > 1) return true;
		if (!cacheMap.count(sum)) cacheMap[sum] = i;
	}
	return false;
}

// 最长同值路径递归函数
int longetUnivalePathTraceback(TreeNode* node, int& result) {
	if (node == NULL) return 0;
	int leftLen = longetUnivalePathTraceback(node->left, result);
	int rightLen = longetUnivalePathTraceback(node->right, result);
	leftLen = (node->left != NULL && node->left->val == node->val) ? leftLen + 1 : 0;
	rightLen = (node->right!=NULL && node->right->val == node->val) ? rightLen + 1 : 0;
	result = max(result, leftLen + rightLen);
	return max(leftLen, rightLen);   // 根节点下只能选一条路径
}

// 687.最长同值路径
int LeetCodeLib::longestUnivaluePath(TreeNode* root) {
	int result = 0;
	longetUnivalePathTraceback(root, result);
	return result;
}


// 62.不同路径
int LeetCodeLib::uniquePaths(int m, int n) {
	vector<vector<int>> pathCache(m,vector<int>(n,0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++){
			pathCache[i][j] = (i == 0 || j == 0)? 1: pathCache[i][j - 1] + pathCache[i - 1][j];
		}
	}
	return pathCache[m - 1][n - 1];
}

// 997. 找到小镇的法官
int LeetCodeLib::findJudge(int N, vector<vector<int>>& trust) {
	if (trust.size() == 0) {
		if (N == 1)
			return 1;
		else
			return -1;
	}
	map<int, vector<int>> trustMap;
	for (int i = 0; i < trust.size(); i++) {
		trustMap[trust[i][0]] = trustMap.count(trust[i][0]) ? vector<int>{ trustMap[trust[i][0]][0] + 1, trustMap[trust[i][0]][1] } : vector<int>{1, 0};
		trustMap[trust[i][1]] = trustMap.count(trust[i][1]) ? vector<int>{ trustMap[trust[i][1]][0] , trustMap[trust[i][1]][1]+1 } : vector<int>{ 0, 1};
	}
	for (auto& it : trustMap) {
		if (it.second[0] == 0 && it.second[1] >= N - 1) return it.first;
	}
	return -1;
}