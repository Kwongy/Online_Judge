class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        one, two, three = 0, 0, 0
        for n in nums:
            # two的相应的位等于1，表示该位出现2次
            two |= (one & n);
            # one的相应的位等于1，表示该位出现1次
            one ^= n;
            # three的相应的位等于1，表示该位出现3次
            three = (one & two);
            # 如果相应的位出现3次，则该位重置为0
            two &= ~three;
            one &= ~three;
        return one