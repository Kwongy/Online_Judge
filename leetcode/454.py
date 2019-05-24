class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        from collections import defaultdict
        dic = defaultdict(int)
        for i in A:
            for j in B:
                dic[i + j] += 1
        cnt = 0
        for i in C:
            for j in D:
                cnt += dic[-(i + j)]

        return cnt