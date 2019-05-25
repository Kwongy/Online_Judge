class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        dic = dict()
        k = 1
        ls = []
        for c in pattern:
            if c not in dic:
                dic[c] = k
                ls.append(k)
                k += 1
            else:
                ls.append(dic[c])
        lst = str.split(' ')
        if len(lst) != len(ls):
            return False
        dit = dict()
        lt = []
        k = 1
        for c in lst:
            if c not in dit:
                dit[c] = k
                lt.append(k)
                k += 1
            else:
                lt.append(dit[c])

        for i in range(len(ls)):
            if lt[i] != ls[i]:
                return False

        return True
