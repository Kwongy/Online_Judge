class Solution:
    def nextGreaterElement(self, n: int) -> int:
        nums = [int(x) for x in str(n)]
        if sorted(nums)[::-1] == nums:
            return -1
        m = len(nums)
        for i in range(m - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                for j in range(m - 1, i, -1):
                    if nums[j] > nums[i]:
                        nums[i], nums[j] = nums[j], nums[i]
                        nums[i + 1:] = sorted(nums[i + 1:])
                        break
                break
        res = 0
        for i in nums:
            res = 10 * res + i
        return res if res<2**31 else -1