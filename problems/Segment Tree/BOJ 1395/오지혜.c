//BOJ_1395

#include <stdio.h>

int N, M;
int tree[100002*4];
int lazy[100002*4];

//pass lazy or accept in the case of leaf
void propagate(int node, int ns, int ne)
{
    int m = (ns + ne) / 2;
    
    if (lazy[node] == 0) return;
    
    if (ns != ne)
    {
        lazy[node * 2] = (m - ns + 1) - lazy[node * 2];
        lazy[node * 2 + 1] = (ne - m) - lazy[node * 2 + 1];
    }
    
    lazy[node] = 0;
    tree[node] = (ne - ns + 1) - tree[node];
}

//assign lazy value and propagate related to the switch ON/OFF
void update(int node, int s, int e, int us, int ue)
{
    propagate(node, s, e);
    
    if (us > e || s > ue)
        return;
    
    if (us <= s && e <= ue)
    {
        lazy[node] = (e - s + 1) - lazy[node];
        propagate(node, s, e);
        return;
    }
    
    int m = (s + e) / 2;
    
    update(node * 2, s, m, us, ue);
    update(node * 2 + 1, m + 1, e, us, ue);
    
    //after applying child propagation, update node value using child value
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

//count the number of ON Switch
int count(int node, int s, int e, int qs, int qe)
{
    propagate(node, s, e);
    
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe)
    {
        return tree[node];
    }
    
    int mid = (s + e) / 2;
    
    return count(node * 2, s, mid, qs, qe)+ count(node * 2 + 1, mid + 1, e, qs, qe);
}

int main()
{
    int N=0, M=0;
    int O=0, S=0, T=0;
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &O, &S, &T);
        
        if (O == 0)
        {
            update(1, 1, N, S, T);
        }
        else if (O == 1)
        {
            printf("%d\n", count(1, 1, N, S, T));
        }
    }
    
    return 0;
}


