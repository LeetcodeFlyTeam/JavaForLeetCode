class Solution(object):
    def twoSum(self, numbers, target):
        for i in range(len(numbers)):
            for j in range(i+1,len(numbers)):
                if numbers[i]+numbers[j] == target:
                    return i+1,j+1
                elif numbers[i]+numbers[j] > target:
                    break

    def twoSum1(self,numbers,target):
        for i in range(len(numbers)):
            a = target - numbers[i]
            if a <numbers[i]:
                break
            elif a in numbers:
                return i+1,numbers.index(a,i+1)+1

    def twoSum2(self, numbers, target):
        l = 0
        r = len(numbers)-1
        while l < r:
            if numbers[l]+numbers[r] == target:
                return l+1,r+1
            elif numbers[l]+numbers[r] > target:
                r = r-1
            else:
                l = l+1




if __name__ == '__main__':
    nums = [0,0,3,4]
    s = Solution()
    print(s.twoSum2(nums,0))