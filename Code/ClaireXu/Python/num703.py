class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.k = k
        self.nums = nums

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        self.nums.append(val)
        self.nums.sort(reverse=True)
        return self.nums[k-1]

if __name__ =='__main__':
    k = 3
    arr = [4, 5, 8, 2]
    arr.sort(reverse= True)
    obj = KthLargest(k, arr)
    print(obj.add(3))
    print(obj.add(5))

