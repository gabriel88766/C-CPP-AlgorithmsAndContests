#!/bin/python3

n = int(input())
list = [int(i) for i in input().split()]
S = 0
for i in range(1, len(list)):
    if(list[i] < list[i-1]):
        S += list[i-1]-list[i]
        list[i] = list[i-1]
print(S)