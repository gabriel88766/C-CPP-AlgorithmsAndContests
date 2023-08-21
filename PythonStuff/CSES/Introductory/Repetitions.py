#!/bin/python3

str = input()
cnt = 0
ans = 0
for i in range(len(str)):
    if(i != 0 and str[i] == str[i-1]):
        cnt += 1
    else:
        cnt = 1
    ans = max(cnt, ans)
print(ans)