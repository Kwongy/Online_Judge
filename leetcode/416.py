from typing import List
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        lens = len(nums)
        a = sum(nums)
        if a % 2 == 1: return False
        c = a >> 1
        # lists = [0] * (c + 1)
        lists = [False] * (c + 1)
        lists[0] = True
        for i in range(lens):
            if nums[i] < c + 1:
                for j in range(c, nums[i]-1, -1):
                    # lists[j] = max(lists[j], lists[j - nums[i]] + nums[i])
        # if lists[c] == c:
        #     return True
        # else:
        #     return False
                    lists[j] = lists[j] or lists[j - nums[i]]
        return lists[-1]

# 使用Python被卡了常， 不能用数去判断是否可构造sum/2的满背包