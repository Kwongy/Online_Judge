class Solution(object):
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        row,col = len(M),len(M[0])
        ans=[ [0]*col for _ in range(row)]
        for r in range(row):
            for c in range(col):
                tmp=[]
                for i in range(-1,2):
                    for j in range(-1,2):
                        if 0<=r+i<row and 0<=c+j<col:
                            tmp.append(M[r+i][c+j])
                lth,sm = len(tmp),sum(tmp)
                ans[r][c]=int(sm/lth)
        return ans