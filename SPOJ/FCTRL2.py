def fac(x):
    if x > 1:
        return fac(x - 1)*x
    else:
        return 1
 
 
T = int(input())
while T>0:
    N = int(input())
    print(fac(N))
    T-=1