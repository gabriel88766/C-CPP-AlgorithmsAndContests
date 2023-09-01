#!/bin/python3

n = int(input())

for i in range(n):
    a = input()
    b = input()
    ok = False
    for j in range(len(a)-1):
        if(a[j] == '0' and b[j] == '0' and a[j+1] == '1' and b[j+1] == '1'):
            ok = True;
    if(ok):
        print("YES")
    else:
        print("NO")