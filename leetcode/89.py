class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans = []
        for i in range(pow(2,n)):
            ans.append((i ^ (i >> 1)))
        return ans