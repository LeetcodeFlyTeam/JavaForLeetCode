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