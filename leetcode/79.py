class Solution:
    flag = False
    dirx = [0, 0, 1, -1]
    diry = [1, -1, 0, 0]
    b = []
    vis = []
    n, m, lens = 0, 0, 0
    w = ""

    def clearzero(self):
        for i in range(self.n):
            for j in range(self.m):
                self.vis[i][j] = False


    def exist(self, board: List[List[str]], word: str) -> bool:
        self.b = board
        self.n = len(board)
        self.m = len(board[0])
        self.w = word
        self.vis = [[False for i in range(self.m)]for i in range(self.n)]
        self.lens = len(word)
        for i in range(self.n):
            for j in range(self.m):
                if board[i][j] == word[0]:
                    self.clearzero()
                    self.vis[i][j] = True
                    self.dfs(i, j, 1)
                    if self.flag == True:
                        return True
        return False

    def dfs(self, x, y, step):
        if step == self.lens:
            self.flag = True
        if self.flag == True:
            return
        for i in range(4):
            dx = x + self.dirx[i]
            dy = y + self.diry[i]
            if dx < 0 or dx == self.n or dy < 0 or dy == self.m or self.vis[dx][dy] == True or self.b[dx][dy] != self.w[
                step]:
                continue
            else:
                self.vis[dx][dy] = True
                self.dfs(dx, dy, step + 1)
                self.vis[dx][dy] = False
