#!/bin/python2
 
import os
import sys
from atexit import register
from io import BytesIO

sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


def build(l, r, p):
    if(l == r):
        st[p] = list[l-1]
    else:
        build(l, (l+r) >> 1, 2*p)
        build(((l+r)>>1)+1, r, 2*p+1)
        st[p] = st[2*p] + st[2*p+1]
 
#use query(l, r, 1, n, 1)
def query(l, r, i, j, p): 
    if(i >= l and r >= j):
        return st[p]
    if(j < l or i > r):
        return 0
    return query(l, r, i, (i+j) >> 1, 2*p) + query(l, r, ((i+j) >> 1) +1, j, 2*p+1)
 
def update(ind, val, i, j, p):
    if(ind > j or ind < i):
        return
    if(i == j):
        st[p] = val
        return
    update(ind, val, i, (i+j) >> 1, 2*p)
    update(ind, val, ((i+j) >> 1 )+1, j, 2*p+1)
    st[p] = st[2*p] + st[2*p+1]
 
n, q = [int(x) for x in input().split()]
st = [0]*4*n
list = [int(x) for x in input().split()]
 
build(1, n, 1)
 
for i in range(q):
    t, l, r = [int(x) for x in input().split()]
    if(t == 1):
        update(l+1, r, 1, n, 1)
    else:
        print(query(l+1, r, 1, n, 1))