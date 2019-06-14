class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        ls = A.split(' ') + B.split(' ')
        from collections import defaultdict
        dic = defaultdict(int)
        for i in ls:
            dic[i] += 1
        ans = []
        for key, value in dic.items():
            if value == 1:
                ans.append(key)
        return ans
