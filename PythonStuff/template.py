## not really a template, just some utils.
##read all input
a = input()

nums = []
for i in range(int(a)):
	b = input()
	#nums.append(int(b)) #nums??


############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))