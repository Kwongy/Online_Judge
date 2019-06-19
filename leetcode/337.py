# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        if root==None:
            return 0
        def helper(root):
            if root==None:
                return [0,0]
            left = helper(root.left)
            right = helper(root.right)
            rob = root.val + left[1] + right[1]
            skip = max(left) + max(right)
            return [rob, skip]
        res = helper(root)
        return max(res)