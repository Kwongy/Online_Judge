class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        cate = set(candies)
        l = len(cate)
        return int(min(l, len(candies) / 2))