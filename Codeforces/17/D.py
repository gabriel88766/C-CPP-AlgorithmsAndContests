def inlt():
    return(list(map(int,input().split())))
def binpow(a, b, m):
    ans = 1
    while(b > 0):
        if((b & 1) == 1):
            ans = (ans * a) % c
        a = (a * a)%c
        b >>= 1
    return ans
l = inlt()
a = l[0]
b = l[1]
c = l[2]

a %= c
d = a - 1
if(d < 0):
    d = d + c

list = []
aux = c
for i in range(100000):
    if(i <= 1):
        continue
    if(i >= aux):
        break
    if((aux % i) == 0):
        list.append(i)
        while((aux % i) == 0):
            aux = aux / i
if(aux > 1 ):
    list.append(aux)
phi = c
for i in list:
    phi = phi // i
    phi = phi * (i-1)
phi = int(phi)
if(b < 100000000):
    res = binpow(a, b-1, c) * d
    res = res % c
else:
    res = binpow(a, b%phi + phi - 1, c) * d
    res = res % c
if(res == 0):
    res = c
print(res)