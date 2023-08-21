#!/bin/python3

n, q = [int(x) for x in input().split()]
list = [int(x) for x in input().split()]
ps = [0]
for i in range(len(list)):
    ps.append(ps[len(ps)-1]+list[i])
for i in range(q):
    l, r = [int(x) for x in input().split()]
    print(ps[r]-ps[l-1])