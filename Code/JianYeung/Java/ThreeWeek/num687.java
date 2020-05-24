/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int maxPath;
    public int longestUnivaluePath(TreeNode root) {
        maxPath = 0;
        pathLength(root);
        return maxPath;
    }

    public int pathLength(TreeNode node) {
        if(node == null) return 0;
        int left = pathLength(node.left);
        int right = pathLength(node.right);
        int leftPathLength = 0;
        int rightPathLength = 0;

        if(node.left != null && node.left.val == node.val) {
            leftPathLength = left + 1; 
        }

        if(node.right != null && node.right.val == node.val) {
            rightPathLength = right + 1;
        }

        maxPath = Math.max(maxPath, (leftPathLength + rightPathLength));
        return Math.max(leftPathLength, rightPathLength);
    }
}