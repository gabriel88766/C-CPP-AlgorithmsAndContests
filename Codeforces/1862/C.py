#!/bin/python3

t = int(input())
for i in range(t):
    n = int(input())
    v = [int(x) for x in input().split()]
    u = []
    for i in range(len(v)):
        j = n//2
        p = 0
        while(j > 0):
            while((p+j) < n and v[p+j] >= (i+1)):
                p += j
            j //= 2
        u.append(p+1)
    if(u == v):
        print("YES")
    else:
        print("NO")