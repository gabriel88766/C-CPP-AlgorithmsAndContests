a = input()
b = input()
c = input()
d = ""
e = ""
for i in range(int(a)):
    if b[i] > c[i]:
        e += b[i]
        d += c[i]
    else:
        d += b[i]
        e += c[i]

print((int(d)*int(e))%998244353)