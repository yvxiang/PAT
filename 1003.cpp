#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x0fffffff
int N,C1,C2,M;
int map[502][502];
int power[502];
int roads[502];
void init()
{
	int i,j;
	for(i=0;i<N;i++) {
		roads[i]=1;
		for(j=0;j<=i;j++)
			map[i][j]=map[j][i]=INF;
	}
}
void dijkstra(int start,int end)
{
	bool visited[502]={false};
	int i,j,min,pos;
	int min_road[502];
	int max_power[502];
	for(i=0;i<N;i++) {
		min_road[i]=map[start][i];
		max_power[i]=power[start]+power[i];
	}
	visited[start]=true;
	min_road[start]=0;
	max_power[start]=power[start];
	for(i=1;i<N;i++) {
		min=INF;
		for(j=0;j<N;j++) {
			if(!visited[j]&&min_road[j]<min) {
				min=min_road[j];
				pos=j;
			}
		}
		visited[pos]=true;
		for(j=0;j<N;j++) {
			if(!visited[j]&&min_road[j]>min+map[pos][j]) {
				min_road[j]=min+map[pos][j];
				max_power[j]=max_power[pos]+power[j];
				roads[j]=roads[pos];
			} else if(!visited[j]&&min_road[j]==min+map[pos][j]) {
				roads[j]=roads[pos]+roads[j];
				if(max_power[j]<max_power[pos]+power[j]) {
					max_power[j]=max_power[pos]+power[j];
				}
			}
		}
	}
	printf("%d %d\n",roads[end],max_power[end]);
}

int main()
{
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	int i,j;
	init();
	for(i=0;i<N;i++)
		scanf("%d",&power[i]);
	int a,b,w;
	for(i=0;i<M;i++) {
		scanf("%d%d%d",&a,&b,&w);
		map[a][b]=map[b][a]=w;
	}
	dijkstra(C1,C2);
	return 0;
}
