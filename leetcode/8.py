class Solution:
    def myAtoi(self, str: str) -> int:
        if len(str) < 1:
            return 0
        minn = -2147483648
        maxn = 2147483647
        for i, c in enumerate(str):
            if c != ' ': break
        num = 0
        flag = False
        if str[i] == '+' or str[i] == '-':
            if len(str) < 2 or str[i + 1].isdigit() == False: return 0
            for j in range(i + 1, len(str)):
                if str[j].isdigit() == False:
                    flag = True
                    break
            if flag == True:
                s = str[i: j]
            else:
                s = str[i: j + 1]
            num = int(s)
        else:
            if str[i].isdigit() == False:
                return 0
            else:
                for j in range(i, len(str)):
                    if str[j].isdigit() == False:
                        flag = True
                        break
                if flag == True:
                    s = str[i: j]
                else:
                    s = str[i: j + 1]
                num = int(s)

        if num > maxn:
            return maxn
        elif num < minn:
            return minn
        else:
            return num