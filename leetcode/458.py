class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        import math
        return int(math.ceil(math.log(buckets,minutesToTest/minutesToDie+1)))