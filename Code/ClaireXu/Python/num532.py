
import collections


class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        res = 0
        c = collections.Counter(nums)
        for i in c:
            if k > 0 and i + k in c or k == 0 and c[i] > 1:
                res += 1
        return res

if __name__ == '__main__':
    list = [1,3,1,5,4]
    k = 0
    print(Solution().findPairs(list,k))

