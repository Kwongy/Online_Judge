class Solution:
    def checkValidString(self, s: str) -> bool:
        lefts,stars=[],[]
        for i,x in enumerate(list(s)):
            if x=='(':
                lefts.append(i)
            elif x=='*':
                stars.append(i)
            else:
                if len(lefts):
                    lefts.pop()
                elif len(stars):
                    stars.pop()
                else:
                    return False
        #检查所有“（”是否都能在“*”中匹配到（“*”的位置大于“（”的位置
        if len(stars)<len(lefts):return False
        for s, l in zip(stars[::-1], lefts[::-1]):
            if s < l: return False
        return True