// Dijk_10217
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;

struct node
{
  int pos, cost, time;
  bool operator<(const node &p) const
  {
    if (this->time == p.time)
      return this->cost > p.cost;
    return this->time > p.time;
  }
};

int dp[101][10001];
vector<node> adj[101];
priority_queue<node> pq;

int dijkstra(int nodes, int money)
{
  for (int i = 0; i < nodes; ++i)
  {
    for (int j = 0; j <= money; ++j)
      dp[i][j] = INF;
  }

  pq = {};
  pq.push({0, 0, 0});
  dp[0][0] = 0;

  while (!pq.empty())
  {
    node top = pq.top();
    pq.pop();

    int cost = top.cost;
    int dtime = top.time;
    int pos = top.pos;
    if (pos == nodes - 1)
      break;

    if (dp[pos][cost] < dtime)
      continue;
    dp[pos][cost] = dtime;

    for (int i = 0; i < adj[pos].size(); ++i)
    {
      node &next = adj[pos][i];

      if (cost + next.cost > money)
        continue;
      if (dp[next.pos][cost + next.cost] <= dtime + next.time)
        continue;

      pq.push((node){next.pos, cost + next.cost, dtime + next.time});
      dp[next.pos][cost + next.cost] = dtime + next.time;
    }
  }

  int ret = INF;
  for (int i = 0; i <= money; ++i)
    ret = min(ret, dp[nodes - 1][i]);
  return ret;
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; ++i)
      adj[i].clear();

    while (k--)
    {
      int u, v, x, d;
      scanf("%d %d %d %d", &u, &v, &x, &d);
      adj[u - 1].push_back({v - 1, x, d});
    }

    int r = dijkstra(n, m);
    if (r < INF)
      printf("%d\n", r);
    else
      puts("Poor KCM");
  }

  return 0;
}