// 맞은사람 중 보고 이해하고 자 한 코드..지만 완전히 이해하지 못함 ㅠㅠ
// 일단.. 참고용(?)으로 제출합니다
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace;

const int Max = 100001;
int n, k;
int l[Max], r[Max], A[Max], B[Max];
bool check[Max];

int main(){
    priority_queue< pair <int, int> > pq;

    scnaf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++){
        scanf("%d", s+i);
        if(1 < i){
            B[i] = A[i] - A[i-1];
            pq.push({-B[i], i});
            L[i] = i-1;
            R[i] = i+1;     // 아예 오른쪽과 왼쪽을 나누어서 분류
        }
    }
    B[1] = B[N + 1] = 1e9; 
    R[1] = 2;
    L[N + 1] = N;
    pq.push({-1e9, 1});
    pq.push({-1e9, N + 1}); // 맨 처음과 맨 끝에 over 되는 값 넣기
    int ans = 0;

    while (K--)
    {
        while (chk[pq.top().second])
            pq.pop();
        int v, id;
        tie(v, id) = pq.top();  // 여기부터가 시작되는데.. 각 변수의 역활이 제대로 이해 안된다
        pq.pop();
        v *= -1;
        ans += v;
        B[id] = B[L[id]] + B[R[id]] - B[id];
        pq.push({-B[id], id});
        chk[L[id]] = chk[R[id]] = 1; // 저 두개의 회사는 이미 방문되서 check!
        L[id] = L[L[id]];
        R[id] = R[R[id]];
        R[L[id]] = id;
        L[R[id]] = id;
    }
    printf("%d", ans);
    return 0;
}