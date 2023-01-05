import math

#naive
num = pow(10, 100000)
a = 1
e = 0
for i in range(2, 1000):
    a *= i
    e += num // a

print("2." + str(e))