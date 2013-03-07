#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int father[10002];
int deepth[10002];
typedef struct Edge {
	int s,e;
}Edge;
Edge edges[10002];

int find_father(int child)
{
	while(father[child]!=child)
		child=father[child];
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
	int d[10002];
	queue<int> Q;
	Q.push(node_number);
	visited[node_number]=true;
	d[node_number]=0;
	while(!Q.empty()) {
		int cur_node=Q.front();
		int i;
		bool flag=false;
		for(i=1;i<N;i++) {
			if(edges[i].s==cur_node&&!visited[edges[i].e]) {
				visited[edges[i].e]=true;
				Q.push(edges[i].e);
				d[edges[i].e]=d[cur_node]+1;
				flag=true;
			} else if(edges[i].e==cur_node&&!visited[edges[i].s]) {
				visited[edges[i].s]=true;
				Q.push(edges[i].s);
				d[edges[i].s]=d[cur_node]+1;
				flag=true;
			}
		}
		if(!flag)
			break;
		Q.pop();
	}
	int i,max_d=-1;
	for(i=1;i<=N;i++)
		if(max_d<d[i])
			max_d=d[i];
	return max_d;
}
void init()
{
	int i;
	for(i=1;i<=N;i++)
		father[i]=i;
}
bool cmp(Edge a,Edge b)
{
	if(a.s!=b.s)
		return a.s<b.s;
	return a.e<b.e;
}
int main()
{
	scanf("%d",&N);
	init();
	int count=0,i,a,b;
	for(i=1;i<N;i++) {
		scanf("%d%d",&a,&b);
		edges[i].s=a;
		edges[i].e=b;
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
