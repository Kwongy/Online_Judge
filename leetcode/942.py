class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        begin = 0
        end = len(S)
        ls = []
        for i in S:
            if i == 'I':
                ls.append(begin)
                begin += 1
            else:
                ls.append(end)
                end -= 1
        ls.append(end)
        return ls
