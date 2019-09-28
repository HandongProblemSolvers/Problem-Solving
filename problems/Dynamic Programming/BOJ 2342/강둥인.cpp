#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int step[100001];
int dp[5][5][100001];
int len;

int solve(int l, int r, int i) {
    if (i == len)
        return 0;

    int& ref = dp[l][r][i];
    if (ref != -1)
        return ref;

    // 처음 (0,0)의 경우
    if (l == 0 && r == 0)
        return ref = solve(step[i], r, i + 1) + 2;

    // 다음 밟아야하는 발판이 현재 발판과 같을 때
    if (l == step[i])
        return ref = solve(l, r, i + 1) + 1;
    else if (r == step[i])
        return ref = solve(l, r, i + 1) + 1;

    // 왼쪽 발판의 3가지 경우
    int left = 0;
    if (l == 0)
        left = solve(step[i], r, i + 1) + 2;
    else if (abs(l - step[i]) == 2)
        left = solve(step[i], r, i + 1) + 4;
    else
        left = solve(step[i], r, i + 1) + 3;

    // 오른쪽 발판의 3가지 경우
    int right = 0;
    if (r == 0)
        right = solve(l, step[i], i + 1) + 2;
    else if (abs(r - step[i]) == 2)
        right = solve(l, step[i], i + 1) + 4;
    else
        right = solve(l, step[i], i + 1) + 3;

    return ref = min(left, right);
}

int main() {
    int input;
    while (1) {
        scanf("%d", &input);
        if (input == 0)
            break;
        else
            step[len++] = input;
    }
    memset(dp, -1, sizeof(dp));

    printf("%d", solve(0, 0, 0));

    return 0;
}


// 두 발이 동시에 움직이지는 않는다.
// 한 발이 1의 위치에 있고, 다른 한 발이 3의 위치에 있을 때, 3을 연속으로 눌러야 한다면,
// 3의 위치에 있는 발로 반복해야 눌러야 한다는 것이다.
// 중앙에 있던 발이 다른 지점으로 움직일 때, 2의 힘을 사용하게 된다.
// 그리고 다른 지점에서 인접한 지점으로 움직일 때는 3의 힘을 사용하게 된다.
// (예를 들면 왼쪽에서 위나 아래로 이동할 때의 이야기이다.)
// 그리고 반대편으로 움직일때는 4의 힘을 사용하게 된다.
// (위쪽에서 아래쪽으로, 또는 오른쪽에서 왼쪽으로).
// 만약 같은 지점을 한번 더 누른다면, 그때는 1의 힘을 사용하게 된다.
// 만약 1 -> 2 -> 2 -> 4를 눌러야 한다고 가정해 보자.
// 당신의 두 발은 처음에 (point 0, point 0)에 위치하여 있을 것이다.
// 그리고 (0, 0) -> (0, 1) -> (2, 1) -> (2, 1) -> (2, 4)로 이동하면,
// 당신은 8의 힘을 사용하게 된다.

// #include <cstdio>
// #include <algorithm>
// #include <cmath>
//
// using namespace std;
//
// int dp[100001][2];
//
// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, -1, 0, 1};
//
// int main() {
//     int dir, i, k;
//     int curL = 0, curR = 0;
//
//     //dp[i][0]: i번째 신호에 왼발이 움직였다
//     //dp[i][1]: i번째 신호에 오른발6yt이 움직였다.
//     i = 0, k = 0;
//
//     while (dir != 0) {
//         scanf("%d", &dir);
//         if (dir == 1)
//             dir = dx[0]
//
//
//
//
//         if (i < 1) {
//             curL = dir;
//             dp[i][0] = 2;
//         }
//
//         else {
//             if (dir == curL) {
//                 dp[i][0] = dp[i-1] + 1;
//                 continue;
//             }
//
//             else {
//                 dp[i][1] = dp[i-1] + 2;
//                 continue;
//             }
//
//             int diffL = abs(dir - curL) % 4;
//             int powerL;
//                 if (diffL == 1 || diffL == 3) powerL = 3;
//                 else if (diffL == 0) powerL = 1;
//                 else powerL = 4;
//
//             int diffR = abs(dir - curR);
//             int powerR;
//                 if (diffR == 1 || diffR == 3) powerR = 3;
//                 else if (diffR == 0) powerR = 1;
//                 else powerR = 4;
//
//             dp[i][0] = dp[i-1][k] + powerL;
//             dp[i][1] = dp[i-1][k] + powerR;
//
//             if (powerL < powerR) {
//                 k = 0;
//                 curL = dir;
//             }
//             else  {
//                 k = 1;
//                 curR = dir;
//             }
//
//             dp[i][k] = min(dp[i][0], dp[i][1]);
//             printf("%d ", dp[i][k]);
//         }
//         i++;
//     }
//
//     printf("%d\n", dp[i-1][k]);
//     return 0;
// }
