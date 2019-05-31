class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        t = int(math.sqrt(area))
        left, right = t, t
        while (left * right != area):
            if (left * right > area):
                left -= 1
            else:
                right += 1
        return [right, left]
