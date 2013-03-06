#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define INF 0x0fffffff
int mat[502][502];
int cost[502][502];
int N,M,S,D;
void dijkstra(int s,int e)
{
	bool visited[502]={false};
	int min_dist[502];
	int min_cost[502];
	int father[502];
	int min=INF,pos;
	int i,j;
	for(i=0;i<N;i++) {
		min_dist[i]=mat[s][i];
		min_cost[i]=cost[s][i];
		father[i]=i;
	}
	visited[s]=false;
	min_dist[s]=0;
	min_cost[s]=0;
	father[s]=s;
	for(i=1;i<N;i++) {
		min=INF;
		for(j=0;j<N;j++) {
			if(!visited[j]&&min_dist[j]<min) {
				pos=j;
				min=min_dist[j];
			}
		}
		visited[pos]=true;
		for(j=0;j<N;j++) {
			if(!visited[j]&&min_dist[j]>min_dist[pos]+mat[pos][j]) {
				min_dist[j]=min_dist[pos]+mat[pos][j];
				min_cost[j]=min_cost[pos]+cost[pos][j];
				father[j]=pos;
			} else if(!visited[j]&&min_dist[j]==min_dist[pos]+mat[pos][j]) {
				if(min_cost[j]>=min_cost[pos]+cost[pos][j]) {
					min_cost[j]=min_cost[pos]+cost[pos][j];
					father[j]=pos;
				}
			}
		}
	}
	stack<int> S;
	int cur=e;
	while(father[cur]!=cur) {
		S.push(cur);
		cur=father[cur];
	}
	printf("%d",s);
	while(!S.empty()) {
		printf(" %d",S.top());
		S.pop();
	}
	printf(" %d %d\n",min_dist[e],min_cost[e]);
}

void init()
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++) {
			mat[i][j]=mat[j][i]=INF;
			cost[i][j]=cost[j][i]=INF;
		}
}
int main()
{
	scanf("%d%d%d%d",&N,&M,&S,&D);
	init();
	int i;
	int a,b,d,c;
	for(i=0;i<M;i++) {
		scanf("%d%d%d%d",&a,&b,&d,&c);
		if(mat[a][b]>d) {
			mat[a][b]=mat[b][a]=d;
			cost[a][b]=cost[b][a]=c;
		}//input is over
	}
	dijkstra(S,D);
	return 0;
}
