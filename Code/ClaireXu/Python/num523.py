class Solution(object):
    def checkSubarraySum(self, nums, k):
        index = 2
        n = len(nums)
        while index <= n:
            for i in range(n):
                if i + index-1 >= n:
                    break
                sum = 0
                for j in range(index):
                    sum += nums[i + j]
                if k != 0 and sum % k == 0:
                    return True
                elif k == 0 and sum == 0:
                    return True
            index += 1
        return False

    def checkSubarraySum_1(self, nums,k):
        length = len(nums)
        if length in [0, 1]:
            return False

        dp = [0 for a in range(length)]
        dp[0] = nums[0]

        for i in range(1, length):
            dp[i] = dp[i - 1] + nums[i]

        for i in range(0, length - 1):
            for j in range(i + 1, length):
                sumn = dp[j] - dp[i] + nums[i]
                if (k == 0 and sumn == 0) or (k != 0 and sumn % k == 0):
                    return True
        return False


if __name__ == '__main__':
    nums = [23,2,6,4,7]
    nums_1 =[0,0]
    print(Solution().checkSubarraySum_1(nums,6))

