#!/bin/python3

n = int(input())
if(n == 2 or n == 3):
    print("NO SOLUTION")
elif(n == 1):
    print(1)
else:
    ans = []
    for i in range(2,n+1,2):
        ans.append(str(i))
    for i in range(1, n+1, 2):
        ans.append(str(i))
    print(" ".join(ans))
    