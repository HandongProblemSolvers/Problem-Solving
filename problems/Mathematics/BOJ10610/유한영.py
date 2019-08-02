N = list(input())
N = list(map(int,N))
N.sort(reverse = True)
if N[-1] != 0 :
    print(-1)
else :
    if sum(N) % 3 != 0 :
        print(-1)
    else :
        for number in N :
            print(number,end='')
