def move_sharks() :
    for i in range(len(sharks)) :
        distance = sharks[i][2] % (C * 2)
        if sharks[i][4] == -1 :
            continue
        elif sharks[i][3] == 1 or sharks[i][3] == 2 : #up, down
            while distance != 0 :
                if sharks[i][3] == 1 :
                    if sharks[i][0] - distance < 0 :
                        distance -= sharks[i][0]
                        sharks[i][0] = 0
                        sharks[i][3] = 2
                    else :
                        sharks[i][0] -= distance
                        distance = 0
                elif sharks[i][3] == 2 :
                    if sharks[i][0] + distance >= R :
                        distance -= abs(R-sharks[i][0])
                        sharks[i][0] = R-1
                        sharks[i][3] = 1
                    else :
                        sharks[i][0] += distance
                        distance = 0
        elif sharks[i][3] == 3 or sharks[i][3] == 4: #right, left
            while distance != 0 :
                if sharks[i][3] == 4 :
                    if sharks[i][1] - distance < 0 :
                        distance -= sharks[i][1]
                        sharks[i][1] = 0
                        sharks[i][3] = 2
                    else :
                        sharks[i][0] -= distance
                        distance = 0
                elif sharks[i][3] == 3 :
                    if sharks[i][1] + distance >= C :
                        distance -= abs(C-sharks[i][1])
                        sharks[i][1] = C-1
                        sharks[i][3] = 1
                    else :
                        sharks[i][1] += distance
                        distance = 0
        if grid[sharks[i][0]][sharks[i][1]] == -1 :
            grid[sharks[i][0]][sharks[i][1]] = i
        elif sharks[grid[sharks[i][0]][sharks[i][1]]][4] < sharks[i][4] :
            sharks[grid[sharks[i][0]][sharks[i][1]]][4] = -1
            grid[sharks[i][0]][sharks[i][1]] = i


R,C,M = map(int,input().split())
grid = [ [-1] * C for i in range(R) ]
sharks = []
nearest_shark = [ float('inf') ] * C
result = 0

for i in range(M) :
    sharks.append(list(map(int,input().split()))) #(r,c) s 속력 d 방향 z 크기
    sharks[i][0] -= 1
    sharks[i][1] -= 1
    grid[sharks[i][0]][sharks[i][1]] = i
    if nearest_shark[sharks[i][1]] > sharks[i][0] :
        nearest_shark[sharks[i][1]] = sharks[i][0] # i, r

for i in range(C) :
    # catch shark
    # grid = shark_id
    result += sharks[grid[i][nearest_shark[i]]][4]
    sharks[grid[i][nearest_shark[i]]][4] = -1
    grid[i][nearest_shark[i]] = -1

    #shark move
    move_sharks()

print(result)

