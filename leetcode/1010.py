class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        from collections import defaultdict
        d = defaultdict(int)
        ans = 0
        for i in time:
            t = i % 60
            j = (60 - t) % 60
            ans += d[j]
            d[t] += 1
        return ans
