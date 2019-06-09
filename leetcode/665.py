class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3: return True
        m = 0
        if nums[0] > nums[1]:
                m+=1
        for i in range(1,len(nums)-1):
            if nums[i]>nums[i+1] :
                m+=1
                if nums[i+1]<nums[i-1] and i+1<len(nums)-1 and nums[i]>nums[i+2]:
                    return False
            if m>=2:
                return False
        return True