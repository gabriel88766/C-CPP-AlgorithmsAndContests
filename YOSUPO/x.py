#!/bin/python3

import sys
sys.set_int_max_str_digits(50000000)



l_fibo = [1, 1, 1, 0]

def multmat(a, b):
    lr = [0, 0, 0, 0]  
    lr[0] = (a[0]*b[0] + a[1]*b[2]) % 100000000000
    lr[1] = (a[0]*b[1] + a[1]*b[3]) % 100000000000
    lr[2] = (a[1]*b[0] + a[3]*b[2]) % 100000000000
    lr[3] = (a[1]*b[1] + a[3]*b[3]) % 100000000000
    return lr


#100101
def fibo(n):
    l_ans = [1, 0, 0, 1]
    l_aux = l_fibo
    while(n):
        if(n & 1):
            l_ans = multmat(l_ans, l_aux)
        l_aux = multmat(l_aux, l_aux)
        n >>= 1
    ans = l_ans[0]
    return ans

def fibo2(n):
    a = 1
    b = 1
    for i in range(2, n+1):
        print(i)

z = fibo(50000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)
#k = z % 100000000000
print(z)
