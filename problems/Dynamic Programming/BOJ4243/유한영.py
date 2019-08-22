import sys

def compute_dist_val(current, left_bound, right_bound, current_val) : 
    global dist_from_start, N, min_val, start
    
    #print(current,left_bound,right_bound,current_val)
    
    if left_bound == 0 and right_bound == N - 1 :
        if min_val > current_val :
            min_val = current_val
        return
    
    if current <= start :
        for i in range(right_bound + 1, N) :
            if left_bound != 0 :
                if ((current_val * 2 + dist_from_start[left_bound] + dist_from_start[i]) * 2 + dist_from_start[i] + dist_from_start[0] ) * 2 + dist_from_start[0] + dist_from_start[N-1] <= min_val :
                    compute_dist_val(i, left_bound, i, current_val + (current_val + dist_from_start[i] + dist_from_start[left_bound]) )
            else :
                compute_dist_val(N-1, left_bound, N-1, current_val * 2 + dist_from_start[N - 1] + dist_from_start[current])                
    elif current > start :
        for i in range(left_bound - 1, -1, -1) :
            if right_bound != N - 1 :
                if ((current_val * 2 + dist_from_start[right_bound] + dist_from_start[i]) * 2 + dist_from_start[i] + dist_from_start[N-1] ) * 2 + dist_from_start[0] + dist_from_start[N-1] <= min_val :
                    compute_dist_val(i, i, right_bound, current_val + (current_val + dist_from_start[i] + dist_from_start[right_bound]))
            else : 
                compute_dist_val(0, 0, right_bound, current_val * 2 + dist_from_start[0] + dist_from_start[current])

T = int(sys.stdin.readline())
for _ in range(T) :
    N = int(sys.stdin.readline())
    start = int(sys.stdin.readline()) - 1
    dist = [0] * N
    
    for i in range(N) :
        if i == start :
            pass
        else :
            dist[i] = int(sys.stdin.readline())
    
    dist_from_start = [0] * N 
    for i in range(N) :
        if i < start : 
            dist_from_start[i] = sum(dist[i:start+1])
        elif i > start : 
            dist_from_start[i] = sum(dist[start+1 : i+1])
        else : 
            dist_from_start[i] = 0
    
    min_val = float('inf')
    compute_dist_val(start,start,start,0)
    print(min_val)



    
