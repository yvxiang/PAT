#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int N;
bool mat[10002][10002];
int father[10002];
int deepth[10002];

int find_father(int child)
{
	if(father[child]==child)
		return father[child];
	father[child]=find_father(father[child]);
	return father[child];
}
void Union(int fa,int fb)
{
	if(fa==fb)
		return ;
	father[fb]=fa;
}
int calc_deepth(int node_number)
{
	bool visited[10002]={false};
	queue<int> Q;
	Q.push(node_number);
	visited[node_number]=true;
	int cur_node;
	int cur_deep=0;
	while(!Q.empty()) {
		cur_deep++;
		int cur_level_width=Q.size();
		int i,j;
		for(i=0;i<cur_level_width;i++) {
			cur_node=Q.front();
			Q.pop();
			for(j=1;j<=N;j++) {
				if(!visited[j]&&mat[cur_node][j]!=0) {
					Q.push(j);
					visited[j]=true;
				}
			}
		}
	}
	return cur_deep;
}
void init()
{
	int i,j;
	for(i=1;i<=N;i++) {
		father[i]=i;
	   	for(j=1;j<=i;j++)
			mat[i][j]=mat[j][i]=0;
	}
}
int main()
{
	scanf("%d",&N);
	init();
	int count=0,i,a,b;
	for(i=1;i<N;i++) {
		scanf("%d%d",&a,&b);
		mat[a][b]=mat[b][a]=1;
		int fa=find_father(a);
		int fb=find_father(b);
		if(fa!=fb) {
			count++;
			Union(fa,fb);
		}
	}
	if(count!=N-1) {
		printf("Error: %d components\n",N-count);
	} else {
		int max_deepth=-1;
		for(i=1;i<=N;i++) {
			deepth[i]=calc_deepth(i);
			if(deepth[i]>max_deepth)
				max_deepth=deepth[i];
		}
		for(i=1;i<=N;i++)
			if(deepth[i]==max_deepth)
				printf("%d\n",i);
	}
	return 0;
}
