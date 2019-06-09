class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        maxn = 0
        while (left < right):
            maxn = max(maxn, min(height[left], height[right]) * (right - left))
            if height[right] > height[left]:
                left += 1
            else:
                right -= 1

        return maxn


