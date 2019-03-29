N, L = map(int, input().split())

sticks = []
for _ in range(N):
	sticks.append(list(map(int, input().split())))
sticks.sort()

# upList already sorted
upList = list(set([x[0] for x in sticks]))
downList = list(set([x[1] for x in sticks]))
downList.sort()

uppers = [0 for _ in range(100001)]
lowers = [0 for _ in range(100001)]
ans = 0
for i in range(N):
	length = L + abs(sticks[i][0] - sticks[i][1])

	up_idx = upList.index(sticks[i][0])
	down_idx = downList.index(sticks[i][1])
	up = uppers[up_idx]
	down = lowers[down_idx]

	uppers[up_idx] = max(up, down + length)
	lowers[down_idx] = max(down, up + length)
	ans = max(uppers[up_idx], max(ans, lowers[down_idx]))

print(ans)
