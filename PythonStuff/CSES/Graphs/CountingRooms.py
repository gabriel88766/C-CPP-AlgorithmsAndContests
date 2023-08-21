#!/bin/python3

from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
l = []
n, m = [int(i) for i in input().split()]
vis = [[False]*m for i in range(n)]

for i in range(n):
    l.append(input())

ans = 0
for i in range(n):
    for j in range(m):
        if(l[i][j] == '.' and vis[i][j] == False):
            q = deque()
            q.append([i, j])
            vis[i][j] = True
            while(len(q) != 0):
                u, v = q[0]
                q.popleft()
                for k in range(4):
                    dsx = u + dx[k]
                    dsy = v + dy[k]
                    if(dsx < 0 or dsx >= n or dsy < 0 or dsy >= m):
                        continue
                    if(vis[dsx][dsy] == False and l[dsx][dsy] == '.'):
                        vis[dsx][dsy] = True
                        q.append([dsx, dsy])
            ans += 1
print(ans)