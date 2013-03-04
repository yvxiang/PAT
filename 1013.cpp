#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x0fffffff
int N,M,K;
int mat[1002][1002];
int mat_back_up[1002][1002];
bool visited[1002]={false};
bool need_to_check[1002]={true};
void init()
{
	int i,j;
	for(i=1;i<=N;i++) {
		need_to_check[i]=true;
		for(j=1;j<=i;j++)
		mat_back_up[i][j]=mat_back_up[j][i]=mat[i][j]=mat[j][i]=INF;
	}
}
void dfs(int num)
{
	visited[num]=true;
	int i;
	for(i=1;i<=N;i++) {
		if(!visited[i]&&mat[num][i]!=INF&&need_to_check[i])
			dfs(i);
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	int i,j;
	init();
	int a,b;
	for(i=0;i<M;i++) {
		scanf("%d%d",&a,&b);
		mat_back_up[a][b]=mat_back_up[b][a]=mat[a][b]=mat[b][a]=1;
	}
	int cur_city;
	for(j=0;j<K;j++) {
		scanf("%d",&cur_city);
		for(i=1;i<=N;i++)
			mat[cur_city][i]=mat[i][cur_city]=INF;
		int count=0;
		need_to_check[cur_city]=false;
		for(i=1;i<=N;i++) {
			if(!visited[i]&&need_to_check[i]) {
				count++;
				dfs(i);
			}
		}
		printf("%d\n",count-1);
		int m,n;
		for(m=1;m<=N;m++)
			for(n=1;n<=N;n++)
				mat[m][n]=mat[n][m]=mat_back_up[m][n];
		memset(visited,false,sizeof(visited));
		memset(need_to_check,true,sizeof(need_to_check));
	}
	return 0;
}
