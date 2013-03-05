#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N,K;
typedef struct Team {
	char number[14];
	int score;
	int region;
	int local_rank;
	int final_rank;
}Team;
Team teams[30005];
void calc_local_rank(int p,int sp,int ep)
{
	if(sp>ep)
		return;
	int r=1;
	int i=sp;
	for(;i<=ep;i++) {
		if(teams[i].score>teams[p].score)
			r++;
	}
	teams[p].local_rank=r;
}
void calc_final_rank(int p,int sp,int ep)
{
	if(sp>ep)
		return;
	int r=1;
	int i;
	for(i=sp;i<=ep;i++) 
		if(teams[i].score>teams[p].score)
			r++;
	teams[p].final_rank=r;
}
bool cmp(Team a,Team b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else 
		return strcmp(a.number,b.number)<0;
}
int main()
{
	scanf("%d",&N);
	int i,pos=1;
	for(i=1;i<=N;i++) {
		scanf("%d",&K);
		int j=0;
		int pre_pos=pos;
		while(j<K) {
			scanf("%s%d",teams[pos].number,&teams[pos].score);
			teams[pos].region=i;
			pos++;
			j++;
		}
		if(pre_pos<=pos) {
			for(j=pre_pos;j<pos;j++) {
				calc_local_rank(j,pre_pos,pos-1);
			}
		}

	}
	pos--;
	printf("%d\n",pos);
	sort(teams+1,teams+pos+1,cmp);
	printf("%s %d %d %d\n",teams[1].number,1,teams[1].region,teams[1].local_rank);
	int fr=1;
	for(i=2;i<=pos;i++) {
		if(teams[i].score!=teams[i-1].score) {
			fr=i;
		}
		printf("%s %d %d %d\n",teams[i].number,fr,teams[i].region,teams[i].local_rank);
	}
	return 0;
}
