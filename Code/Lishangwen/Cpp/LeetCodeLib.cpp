#include "LeetCodeLib.h"
#include "map"
#include "queue"
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

// 997. 找到小镇的法官map缓存
int LeetCodeLib::findJudge(int N, vector<vector<int>>& trust) {
	if (trust.size() == 0 && N == 1) return 1;
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

// 997. 找到小镇的法官map缓存 数组缓存
int LeetCodeLib::findJudgeArrayCache(int N, vector<vector<int>>& trust) {
	if (trust.size() == 0 && N == 1) return 1;
	if (trust.size() < N - 1) return -1;
	vector<vector<int>> trustCach(N+1,vector<int>{ 0,0 });
	for (int i = 0; i < trust.size(); i++) {
		trustCach[trust[i][0]][0]++;
		trustCach[trust[i][1]][1]++;
	}
	for (int j = 0; j < trustCach.size();j++) {
		if (trustCach[j][0] == 0 && trustCach[j][1] >= N - 1) return j;
	}
	return -1;
}


// 1311. 获取你好友已观看的视频
vector<string> LeetCodeLib::watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
	vector<bool> visitTag(friends.size());
	queue<int> q;
	q.push(id);
	visitTag[id] = true;
	int queueSize;
	for (int i = 1; i <= level; i++) {
		queueSize = q.size();
		for (int j = 0; j < queueSize; j++) {
			int curId = q.front();
			q.pop();
			for (auto friendId : friends[curId]) {
				if (!visitTag[friendId]) {
					q.push(friendId);
					visitTag[friendId] = true;
				}
			}
		}
	}
	queueSize = q.size();
	map<string, int> videoMap;
	for (int k = 0; k < queueSize; k++) {
		int tempId = q.front();
		q.pop();
		for (auto videoName : watchedVideos[tempId]) {
			if (videoMap.find(videoName) != videoMap.end()) {
				videoMap[videoName]++;
			}
			else{
				videoMap[videoName] = 1;
			}
		}
	}
	vector<pair<string, int> > vpr;
	for (map<string, int>::iterator it = videoMap.begin(); it != videoMap.end(); it++) {
		vpr.push_back(make_pair(it->first, it->second));
	}
	sort(vpr.begin(), vpr.end(), [](const pair<string, int>& p, const pair<string, int>& q) {
		return p.second < q.second || (p.second == q.second && p.first < q.first);
		});
	vector<string> resultArray;
	for (auto pair : vpr) {
		resultArray.push_back(pair.first);
	}
	return resultArray;
}


// 101.对称二叉树
bool LeetCodeLib::isSymmetric(TreeNode* root) {
	if (root->left == NULL || root->right == NULL) {
		if (root->left == NULL && root->right == NULL)
			return true;
		else
			return false;
	}
	queue<TreeNode*> leftQueue, rightQueue;
	leftQueue.push(root->left);
	rightQueue.push(root->right);
	while (leftQueue.size() > 0 && rightQueue.size() > 0&&leftQueue.size()==rightQueue.size()) {
		for (int i = 0; i < leftQueue.size(); i++) {
			auto lNode = leftQueue.front();
			leftQueue.pop();
			auto rNode = rightQueue.front();
			rightQueue.pop();
			if (lNode->val != rNode->val) return false;
			auto lLeftChild = lNode->left;
			auto lRightChild = lNode->right;
			auto rLeftChild = rNode->left;
			auto rRithChild = rNode->right;
			if (lLeftChild != NULL && rRithChild != NULL) {
				if (lLeftChild->val == rRithChild->val) {
					leftQueue.push(lLeftChild);
					rightQueue.push(rRithChild);
				}
				else
				{
					return false;
				}
			}
			else if ((lLeftChild != NULL && rRithChild == NULL) || (lLeftChild == NULL && rRithChild != NULL)) {
				return false;
			}
			if (lRightChild != NULL && rLeftChild != NULL) {
				if (lRightChild->val == rLeftChild->val) {
					leftQueue.push(lRightChild);
					rightQueue.push(rLeftChild);
				}
				else
				{
					return false;
				}
			}
			else if ((lRightChild != NULL && rLeftChild == NULL) || (lRightChild == NULL && rLeftChild != NULL)) {
				return false;
			}
		}
	}
	if (leftQueue.size() == 0 && rightQueue.size() == 0)
		return true;
	else
		return false;
}