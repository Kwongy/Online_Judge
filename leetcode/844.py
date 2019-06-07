class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def process(string):
            ans = []
            for i in string:
                if i != '#':
                    ans.append(i)
                else:
                    if len(ans) != 0:
                        ans.pop()
            return ans
        n1 = process(S)
        n2 = process(T)
        flag = True
        if len(n1) != len(n2):
            flag = False
        else:
            for i in range(len(n1)):
                if n1[i] != n2[i]:
                    flag = False
                    break
        return flag