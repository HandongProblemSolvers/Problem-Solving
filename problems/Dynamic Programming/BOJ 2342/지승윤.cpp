#include <cstdio>
#include <algorithm>
#define INF 1000000000

using namespace std;

int d[5][5], p[5][5];

int main(){
	int t[5][5]={INF, 2, 2, 2, 2, 
				 INF, 1, 3, 4, 3,
				 INF, 3, 1, 3, 4,
				 INF, 4, 3, 1, 3,
				 INF, 3, 4, 3, 1};

	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			d[i][j]=INF;
	
	d[0][0]=0;
	while(1){
		int k;
		scanf("%d", &k);
		if(k==0)
			break;
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				p[i][j]=d[i][j];
				d[i][j]=INF;
			}
		}
		
		for(int i=0; i<5; i++){
			if(i!=k)
				for(int j=0; j<5; j++)
					d[i][k] = min(d[i][k], p[i][j]+t[j][k]);
		}
		for(int j=0; j<5; j++){
			if(j!=k)
				for(int i=0; i<5; i++)
					d[k][j] = min(d[k][j], p[i][j]+t[i][k]);
		}		
	}
	int f=INF;
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			f=min(f, d[i][j]);
	printf("%d\n", f);
}
