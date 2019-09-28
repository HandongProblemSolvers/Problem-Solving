// union_방청소_9938
#include <cstdio>
using namespace std;

int parent[300001];
bool taken[300001];
int n, l;

int find(int a){
  if(parent[a] == a) return a;
  return parent[a] = find(parent[a]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  parent[a] = b;
  puts("LADICA");
}

int main(){
  scanf("%d %d", &n, &l);

  for(int i = 1; i <= l; i++)
    parent[i] = i;

  for(int i = 0; i < n; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    if(!taken[a]){
      taken[a] = true;
      merge(a, b);
    } else if(!taken[b]){
      taken[b] = true;
      merge(b, a);
    } else if(!taken[find(a)]){
      taken[find(a)] = true;
      merge(a, b);
    } else if(!taken[find(b)]){
      taken[find(b)] = true;
      merge(b, a);
    }
    else puts("SMECE");
  }
  return 0;
}
