from queue import Queue
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        init = image[sr][sc]
        dirx = [1, -1, 0, 0]
        diry = [0, 0, 1, -1]
        q = Queue()
        n, m = len(image), len(image[0])
        vis = [[False for i in range(m)] for i in range(n)]
        q.put([sr, sc])
        vis[sr][sc] = True
        image[sr][sc] = newColor
        while not q.empty():
            p = q.get()
            for i in range(4):
                dx = p[0] + dirx[i]
                dy = p[1] + diry[i]
                if dx >= 0 and dy >= 0 and dx < n and dy < m and vis[dx][dy] == False and image[dx][dy] == init:
                    vis[dx][dy] = True
                    image[dx][dy] = newColor
                    q.put([dx, dy])

        return image



