class Solution:
    def solveEquation(self, equation: str) -> str:

        a, b = equation.split('=')
        if a[0] != '-':
            a = '+' + a
        if b[0] != '-':
            b = '+' + b
        n= self.getx(a.replace('+x', '+1x').replace('-x','-1x'))
        m= self.getx(b.replace('+x', '+1x').replace('-x','-1x'))
        n1 = n[0] - m[0]
        n2 = -n[1] + m[1]
        if n1 == 0:
            if n2 == 0:
                return "Infinite solutions"
            else:
                return "No solution"
        else:
            return "x=" + str(int(n2 / n1))

    def getx(self, string):
        i, k = 0, 0
        string = string +  '+'
        a, b = 0, 0
        for j in range(len(string)):
            if (string[j] in ['+', '-']):
                k += 1
            if k == 2:
                k = 1
                st = string[j - i : j]
                i = 0
                if 'x' in st:
                    a += int(st[0 : len(st) - 1])
                else:
                    b += int(st)
            i += 1
        return [a, b]