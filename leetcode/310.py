class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        from collections import defaultdict
        graph = defaultdict(list)
        if not edges: return [0]
        for x, y in edges:
            graph[x].append(y)
            graph[y].append(x)

        leaves = {i for i in graph if len(graph[i]) == 1}
        while n > 2:
            n -= len(leaves)
            nxt = set()
            for leave in leaves:
                tmp = graph[leave].pop()
                graph[tmp].remove(leave)
                if len(graph[tmp]) == 1:
                    nxt.add(tmp)
            leaves = nxt
        return list(leaves)