#!/usr/bin/python

a = input()

nums = []
for i in range(int(a)):
	b = input()
	nums.append(int(b))

fact = [ 1 ]
for i in range(100):
	if i != 0:
		fact.append(i * fact[i-1])

for i in nums:
	print(fact[i])
