class Solution:
    def findNthDigit(self, n: int) -> int:
        if n < 10:
            return n
        a = [0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889]
        for i in range(1, len(a)):
            if a[i] >= n:
                return int(str((n - 1 - a[i - 1]) / i + 10 ** (i - 1))[(n - 1 - a[i - 1]) % i])
                            # 哪个数                                       ## 哪一位
                break
        return 0


