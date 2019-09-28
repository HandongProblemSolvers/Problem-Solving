#include <cstdio>

int n;
const int _size = 1000001;
int a[_size],count[_size];

int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);

    for(int i=1; i<=n; i++){
        if(count[a[i]+1]){
            count[a[i]+1]--;
            count[a[i]]++;
        } else {
            count[a[i]]++;
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++) ans += count[i];
    printf("%d\n",ans);

    return 0;
}