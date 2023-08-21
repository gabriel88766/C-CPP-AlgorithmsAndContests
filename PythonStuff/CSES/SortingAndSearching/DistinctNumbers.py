#!/bin/python3

n = int(input())
list = [int(i) for i in input().split()]
list.sort()
ans = 1
for i in range(1, len(list)):
    if(list[i] != list[i-1]):
        ans += 1
print(ans)