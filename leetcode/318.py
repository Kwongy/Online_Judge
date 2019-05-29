class Solution:
    def maxProduct(self, words: List[str]) -> int:
        if not words:
            return 0
        n = len(words)
        flag = [0 for i in range(n)]
        for idx, word in enumerate(words):
            for alp in word:
                flag[idx] |= 1 << ord(alp) - ord('a')
        max_num = 0
        for i in range(n):
            for j in range(i+1,n):
                if flag[i] & flag[j]==0:
                    max_num = max(max_num,len(words[i])*len(words[j]))
        return max_num