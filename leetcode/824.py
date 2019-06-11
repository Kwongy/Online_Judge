class Solution:
    def toGoatLatin(self, S: str) -> str:
        mu = ['A','E','I','O','U','a','e','i','o','u']
        ls = S.split()
        ans = ''
        cnt = 0
        for i in ls:
            cnt += 1
            if i[0] in mu:
                i = i+'ma'
            elif i[0] not in mu:
                i = i[:0] + i[(1):] +i[0] +'ma'
            i = i + 'a'*cnt
            ans = ans + i +' '
        return (ans.rstrip())