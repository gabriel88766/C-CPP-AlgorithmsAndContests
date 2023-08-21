#!/bin/python3
 
n = int(input())
s = set()
for i in range(1, n+1):
	s.add(i)
 
nums = [int(i) for i in input().split()]
 
for i in nums:
	s.remove(i)
 
for i in range(1,n+1):
	if i in s:
		print(i)