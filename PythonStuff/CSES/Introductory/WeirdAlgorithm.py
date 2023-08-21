#!/bin/python3
 
n = int(input())
ans = str(n) + " "
while(n != 1):
	if(n%2 == 1):
		n = 3*n + 1
	else:
		n //= 2
	ans += str(n) + " "
 
print(ans)