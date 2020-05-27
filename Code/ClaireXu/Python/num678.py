# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        else:
            self.helper(root, root.val)
            return self.max

    def helper(self, root, preVal):
        if root is None:
            return 0
        if root.val == preVal:
            l = self.helper(root.left, root.val)
            r = self.helper(root.right, root.val)
            if l + r > self.max:
                self.max = l + r
            return max(l, r) + 1
        else:
            self.helper(root, root.val)
            return 0
if __name__ == '__main__':
    root = TreeNode(5)
    root1 = TreeNode(4)
    root2 = TreeNode(5)
    root3 = TreeNode(1)
    root4 = TreeNode(1)
    root5 = TreeNode(5)
    root.left = root1
    root.right = root2
 