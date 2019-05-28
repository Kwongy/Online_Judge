from collections import defaultdict
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
#         i = 0
#         dic = defaultdict(int)
#         for i in nums:
#             dic[i] += 1
#             if(dic[i] == 2):
#                 return True 
#         return False
        return len(set(nums)) != len(nums)