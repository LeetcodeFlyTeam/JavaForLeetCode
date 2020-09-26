#include "LeetCodeLib.h"
#include "map"
#include "queue"
#include "set"
#include "stack"
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

// // 997. 找到小镇的法官map缓存
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


// 122.买卖股票的最佳时机II
int LeetCodeLib::maxProfit(vector<int>& prices){
	if (prices.size() < 2) return 0;
	int moneyCount = 0, topPrice = -1, bottomPrice = -1;
	for (int i = 0; i < prices.size(); i++) {
		if (i == 0) {
			if (prices[i] <= prices[i + 1]) bottomPrice = prices[0];
		}
		else if (i > 0 && i < prices.size() - 1) {
			if (prices[i] > prices[i + 1] && prices[i] >= prices[i - 1]) {
				topPrice = prices[i];
			}
			else if (prices[i] <= prices[i + 1] && prices[i] < prices[i - 1]) {
				bottomPrice = prices[i];
			}
		}
		else if (i == prices.size() - 1) {
			if (prices[i] >= prices[i-1]) topPrice = prices[i];
		}
		if (topPrice != -1 && bottomPrice != -1) {
			moneyCount += topPrice - bottomPrice;
			topPrice = bottomPrice = -1;
		}
	}
	return moneyCount;
}

// 35.搜索插入位置
int LeetCodeLib::searchInsert(vector<int>& nums, int target){
	if (nums.size() == 0) return 0;
	int headPos = 0, endPos = nums.size() - 1;
	while (headPos <= endPos) {
		if (nums[headPos] == target) return headPos;
		if (nums[endPos] == target) return endPos;
		if (headPos == endPos) {
			if (nums[headPos] > target)
				return headPos;
			else
				return headPos + 1;
		}
		else if (headPos == endPos - 1) {
			if (target > nums[headPos] && target < nums[endPos]) {
				return headPos + 1;
			}
		}
		if (nums[endPos] > target) endPos--;
		if (nums[headPos] < target) headPos++;
	}
	return 0;
}

// 198. 打家劫舍
int LeetCodeLib::rob(vector<int>& nums){
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];
	int robSumA=0, robSumB=0;
	for (int i = 0; i < nums.size(); i++) {
		if (i % 2 == 0)
			robSumA = max(nums[i] + robSumA, robSumB);
		else
			robSumB = max(nums[i] + robSumB, robSumA);
	}
	return max(robSumA,robSumB);
}

// 292. Nim 游戏
bool LeetCodeLib::canWinNim(int n) {
	return n % 4 != 0;
}

// 8. 字符串转换整数 (atoi)
int LeetCodeLib::myAtoi(string str){
	map<string, int> numMap;
	numMap["0"] = 0;
	numMap["1"] = 1;
	numMap["2"] = 2;
	numMap["3"] = 3;
	numMap["4"] = 4;
	numMap["5"] = 5;
	numMap["6"] = 6;
	numMap["7"] = 7;
	numMap["8"] = 8;
	numMap["9"] = 9;
	int sum = 0;
	bool isBegain = false;
	bool isPositive = true;
	for (int i = 0; i < str.length(); i++) {
		string curStr = str.substr(i, 1);
		if (!isBegain) {
			if (curStr != " " && numMap.count(curStr)<=0&& curStr !="-"&& curStr !="+") {
				return 0;
			}
			else if (curStr == " ")
			{
				continue;
			}
			else if (curStr == "+")
			{
				isBegain = true;
				continue;
			}
			else if (curStr == "-")
			{
				isBegain = true;
				isPositive = false;
				continue;
			}
			else if (numMap.count(curStr) > 0)
			{
				isBegain = true;
				sum = numMap[curStr];
				continue;
			}
		}
		else {
			if (numMap.count(curStr)>0)
			{
				if (isPositive)
				{
					if (sum>INT_MAX/10||(sum==INT_MAX/10&& numMap[curStr]>INT_MAX%10))
					{
						return INT_MAX;
					}
					else
					{
						sum = sum * 10 + numMap[curStr];
					}
				}
				else
				{
					if (sum<INT_MIN/10||(sum==INT_MIN/10&& numMap[curStr]+ INT_MIN % 10 >0))
					{
						return INT_MIN;
					}
					else
					{
						sum = sum * 10 - numMap[curStr];
					}
				}
			}
			else
			{
				return sum;
			}
		}
	}
	return sum;
}

// 168. Excel表列名称
string LeetCodeLib::convertToTitle(int n) {
	string result = "";
	while (n > 0) {
		int tempNum = n % 26;
		tempNum = (tempNum == 0) ? 26 : tempNum;
		n = (n-tempNum)/ 26;
		result.push_back('A'+ tempNum-1);
	}
	reverse(result.begin(), result.end());
	return result;
}

// 剑指 Offer 59 - I. 滑动窗口的最大值
vector<int> LeetCodeLib::maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> result;
	if (nums.size() == 0) return result;
	for (int i = 0; i <= nums.size() - k; i++) {
		int tempMax = nums[i];
		for (int j = i + 1; j < i + k; j++){
			tempMax = max(tempMax, nums[j]);
		}
		result.push_back(tempMax);
	}
	return result;
}

//215. 数组中的第K个最大元素
int LeetCodeLib::findKthLargest(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	return nums[nums.size() - k];
}

// 1042. 不邻接植花
vector<int> LeetCodeLib::gardenNoAdj(int N, vector<vector<int>>& paths){
	vector<vector<int>> G(N);
    // 建立邻接表
	for (int i = 0; i < paths.size(); i++) {
		
		G[paths[i][1] - 1].push_back(paths[i][0]-1);
		G[paths[i][0] - 1].push_back(paths[i][1]-1);
	}
	vector<int> result(N,0);
	for (int i = 0; i < N; i++) {
		set<int> colors{1, 2, 3, 4};
		for (int j = 0; j < G[i].size();j++) {
			colors.erase(result[G[i][j]]);
		}
		result[i] = *(colors.begin());
	}
	return result;
}

//207. 课程表
bool LeetCodeLib::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> G(numCourses);
	vector<int> indegress(numCourses, 0);
	for (int i = 0; i < prerequisites.size(); i++) {
		indegress[prerequisites[i][0]]++;  // 计算入度
		G[prerequisites[i][1]].push_back(prerequisites[i][0]);
	}
	queue<int> zeroIdegQueue;
	for (int i = 0; i < indegress.size(); i++) {
		if (indegress[i] == 0)
			zeroIdegQueue.push(i);   // 只能从入度为0的课程开始学
	}
	while (!zeroIdegQueue.empty()) {
		int pre = zeroIdegQueue.front();
		zeroIdegQueue.pop();
		numCourses--;
		for (int j = 0; j < G[pre].size(); j++) {
			if (--indegress[G[pre][j]] == 0) // 上一门学了后，入度减小，只有减小到0后才能开始学习
				zeroIdegQueue.push(G[pre][j]);
		}
	}
	return numCourses == 0;
}



// 80.删除排序数组中的重复项 II
int LeetCodeLib::removeDuplicates(vector<int>& nums)
{
	if (nums.size() < 3) return nums.size();
	int count = 1, j = 1;
	for (int i = 1; i < nums.size(); i++) {
		count = (nums[i] == nums[i - 1]) ? count + 1 : 1;
		if (count < 3)
			nums[j++] = nums[i];
	}
	return j;
}

// 53. 最大子序和
int LeetCodeLib::maxSubArray(vector<int>& nums)
{
	int sum = nums[0];
	int result = sum;
	for (int i = 1; i < nums.size(); i++)
	{
		sum = max(nums[i], sum + nums[i]);
		result = max(result, sum);
	}
	return result;
}

bool isOpString(string inStr) {
	return inStr == "+" || inStr == "-" || inStr == "*" || inStr == "/";
}

int calculate(int a, int b, string opStr)
{
	if (opStr == "+")
		return a + b;
	else if (opStr == "-")
		return a - b;
	else if (opStr == "*")
		return a * b;
	else if (opStr == "/")
		return a / b;
	else
		return 0;
}

int LeetCodeLib::evalRPN(vector<string>& tokens)
{
	stack<int> opStack;
	for (int i = 0; i < tokens.size(); i++) {
		string ele = tokens[i];
		if (!isOpString(ele)) {
			opStack.push(atoi(ele.c_str()));
		}
		else if(opStack.size()>=2)
		{
			int secondNum = opStack.top();
			opStack.pop();
			int firstNum = opStack.top();
			opStack.pop();
			opStack.push(calculate(firstNum, secondNum, ele));
		}
	}
	if (opStack.size() > 0)
		return opStack.top();
	else
		return 0;
}

// 14.最长公共前缀
string LeetCodeLib::longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0]; 
	string firstStr = strs[0];
	string result = "";
	for (int i = 0; i < firstStr.length(); i++)
	{
		string tempStr = firstStr.substr(i, 1);
		for (int j = 1; j < strs.size(); j++)
		{
			if (i > strs[j].length()||firstStr[i]!=strs[j][i]) 
			{
				return result;
			}
		}
		result = result + tempStr;
	}
	return result;
}

// 81. 搜索旋转排序数组 II
bool LeetCodeLib::search(vector<int> & nums, int target)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target) return true;
	}
	return false;
}

// 392. 判断子序列
bool LeetCodeLib::isSubsequence(string s, string t)
{
	int findCount = 0;
	for (int i = 0; i < t.length()&& findCount <s.length(); i++)
	{
		if (s[findCount] == t[i]) findCount++;
	}
	return findCount == s.length();
}


// 382.链表随机节点
int LeetCodeLib::getRandom()
{
	ListNode* cur = myListNodeHead;
	int val = 0;
	int count = 0;
	while (cur)
	{
		count++;
		int randNum = rand() % count + 1;
		if (randNum == count) val = cur->val;
		cur = cur->next;
	}
	return val;
}


// 172.阶乘后的零
int LeetCodeLib::trailingZeroes(int n)
{
	int zeroCount = 0;
	while (n > 0)
	{
		n /= 5;
		zeroCount += n;
	}
	return zeroCount;
}

// 143. 重排链表
void LeetCodeLib::reorderList(ListNode* head)
{
	stack<ListNode*> nodeCache;
	ListNode* insertPosPtr = head;  // 被插入位置
	ListNode* tempNode = head;
	while (tempNode)
	{
		nodeCache.push(tempNode);
		tempNode = tempNode->next;
	}
	while (insertPosPtr&&insertPosPtr->next && insertPosPtr->next != nodeCache.top())
	{
		ListNode* moveNode = nodeCache.top();
		nodeCache.pop();
		nodeCache.top()->next = NULL;
		moveNode->next = insertPosPtr->next;
		insertPosPtr->next = moveNode;
		insertPosPtr = moveNode->next;
	}
}

// 877. 石子游戏 dp
bool LeetCodeLib::stoneGame(vector<int> &piles) {
    vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0));
    for(int i=0;i<piles.size();i++)
        dp[i][i]=piles[i];
    for(int i=0;i<piles.size()-1;i++)
    {
        for(int j=i+1;j<piles.size();j++)
        {
            dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
        }
    }
    return dp[0][piles.size()-1]>0;
}


// 155. 最小栈
void MinStack::push(int x)
{
	stackData.push_back(x);
	minValue = (stackData.size() == 1) ? x : min(x, minValue);
}


void MinStack::pop()
{
	if (stackData.size() > 0) {
		int topValue = top();
		stackData.erase(stackData.end() - 1);
		if (stackData.size() == 0)
		{
			minValue = 0;
		}
		else if(minValue==topValue)
		{
			minValue = stackData[0];
			for (int e:stackData) {
				minValue = min(e, minValue);
			}
		}
	}
}

int MinStack::top()
{
	if (stackData.size() > 0) {
		return stackData[stackData.size()-1];
	}
	else
	{
		return 0;
	}
	
}

int MinStack::getMin()
{
	return minValue;
}



