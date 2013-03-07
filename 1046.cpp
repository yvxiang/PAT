#include <stdio.h>
int N,M;
int dis[100002];
int main()
{
	scanf("%d",&N);
	int i;
	dis[0]=0;
	dis[1]=0;
	int total=0;
	for(i=2;i<=N+1;i++) {
		scanf("%d",&dis[i]);
		total+=dis[i];
		dis[i]+=dis[i-1];
	}//dis[i] stands for from 1 to	i 
	scanf("%d",&M);
	for(i=0;i<M;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b)
			printf("0\n");
		if(a>b) {
			int temp=a;
			a=b;
			b=temp;
		}
		if(dis[b]-dis[a]>total/2)
			printf("%d\n",total-(dis[b]-dis[a]));
		else
			printf("%d\n",dis[b]-dis[a]);
	}
	return 0;
}



