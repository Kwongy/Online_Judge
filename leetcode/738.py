class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        s = str(N)
        pos = 0
        for i in range(1, len(s)):
            if s[i] > s[i - 1]:
                pos = i
            elif s[i] < s[i - 1]:
                return int(str(int(s[0:pos+1]) - 1) + "9" * (len(s) - pos - 1))
        return N