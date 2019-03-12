//BOJ5573 산책
#include <cstdio>
using namespace std;
#define MAX_W 1001

int W, H, N, board[MAX_W][MAX_W], dp[MAX_W][MAX_W][2];

int main(){
	scanf("%d %d %d", &H, &W, &N);
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			scanf("%d ", &board[i][j]);

	//N번째를 찾아야 하기에 바로 전의 상태를 확인
	N--;
	dp[0][1][0] = N;
	//아래로 이동하면 0->1, 오른쪽으로 이동하면 1->0을 해줘야함.
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			int c = dp[i-1][j][0] + dp[i][j-1][1];
			dp[i][j][0] = board[i][j] ? c/2 : c/2 + c%2;
			dp[i][j][1] = board[i][j] ? c/2 + c%2 : c/2;
		}
	}

	//마지막으로 결과를 합침.
    int ex = 1, ey = 1;
	while(ex <= H && ey <= W){
		int result = dp[ex][ey][0] + dp[ex][ey][1];
		if(result%2) board[ex][ey] = !board[ex][ey];
		if(board[ex][ey]) ey++;
		else ex++;
	}
	printf("%d %d", ex, ey);

	return 0;
}