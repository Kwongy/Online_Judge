# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        ls = []
        def dfs(self, root):
            if root != None :
                ls.append(root.val)
            if root.left != None :
                dfs(self,root.left)
            if root.right != None :
                dfs(self,root.right)
        dfs(self,root)
        ls.sort()
        minn = 0x3f3f3f3f
        for i in range(1, len(ls)):
            minn = min(minn, ls[i] - ls[i-1])
        return minn

# class Solution(object):
#     def minDiffInBST(self, root):
#         in_order = lambda r: in_order(r.left) + [r.val] + in_order(r.right) if r else[]
#         vals = in_order(root)
#         return min([vals[i+1] - vals[i] for i in range(len(vals)-1)])