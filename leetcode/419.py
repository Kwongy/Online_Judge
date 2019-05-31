class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        cnt = 0
        n = len(board)
        m = len(board[0])
        vis = [[False for i in range(m)] for i in range(n)]
        def dfs(x, y):
            for i in range(x, n):
                if(board[i][y] == 'X'):
                    vis[i][y] = True
                else:
                    break;
            for i in range(y, m):
                if(board[x][i] == 'X'):
                    vis[x][i] = True
                else:
                    break;
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'X' and vis[i][j] == False:
                    cnt += 1
                    dfs(i, j)
        return cnt