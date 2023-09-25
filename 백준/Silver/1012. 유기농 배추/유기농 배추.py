import sys


def dfs(x: int, y: int):
    if x < 0 or x >= N or y < 0 or y >= M:
        return
    if graph[x][y] == 1:
        graph[x][y] = 0
        dfs(x, y + 1)
        dfs(x, y - 1)
        dfs(x - 1, y)
        dfs(x + 1, y)
        return


sys.setrecursionlimit(10 ** 8)

case = int(input())
for i in range(case):
    M, N, K = map(int, sys.stdin.readline().split())
    graph = [[0] * M for i in range(N)]
    for j in range(K):
        x, y = map(int, sys.stdin.readline().split())
        graph[y][x] = 1
    count = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                dfs(i, j)
                count += 1

    print(count)
