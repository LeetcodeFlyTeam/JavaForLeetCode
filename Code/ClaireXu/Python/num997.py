class Solution(object):
    def findJudge(self, N, trust):
        l1 = []
        l2 = []
        for i in trust:
            l1.append(i[0])
            l2.append(i[1])
        for i in range(1,N+1):
            if i not in l1 and l2.count(i)== N-1:
                return i
        return -1



if __name__ == '__main__':
    trust = [[1,3],[2,3],[3,1]]
    print(Solution().findJudge(3,trust))