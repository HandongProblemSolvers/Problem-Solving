import sys
t = int(sys.stdin.readline())

def gcd(a,b) :
    if b == 0 :
        return a
    return gcd(b, a%b)

def extendedEA (a,b) :
    t1,t2 = 0,1
    tmp = a
    while b != 0 :
        q = int(a / b)
        r = a % b
        t = t1 - q * t2
        a = b
        b = r
        t1 = t2
        t2 = t
    while t1 < 0 :
        t1 = t1 + tmp
    return t1

for _ in range(t) :
    K,C = map(int,sys.stdin.readline().split())
    if C == 1 :
        if K + 1 > 10 ** 9 :
            print("IMPOSSIBLE")
            continue
        else :
            print(K+1)
            continue
    elif K == 1 :
        print(1)
        continue
    elif gcd(K,C) != 1 :
        print("IMPOSSIBLE")
        continue
        
    result = extendedEA(K,C)
    if result > 10 ** 9 :
        print("IMPOSSIBLE")
    else :
        print(result)

    
