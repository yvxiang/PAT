#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int favorite_color[202];
int stripe[10002];
int M,N,L;
bool occur(int color,int favorite[],int len)
{
	int i;
	for(i=0;i<len;i++)
		if(favorite_color[i]==color)
			return true;
	return false;
}
bool check_after(int num_to_be_checked,int num_before,int L)
{
	int i;
	for(i=0;i<L;i++)
		if(favorite_color[i]==num_to_be_checked)
			break;
	int pos1=i;
	for(i=0;i<L;i++)
		if(favorite_color[i]==num_before)
			break;
	int pos2=i;
	if(pos1>pos2)
		return true;
	return false;
}
int main()
{
	int color[10002];//color[i] stands for befoe and include i,the longest string's end color 
	int max_len[10002];
	int i;
	scanf("%d",&N);
	scanf("%d",&M);
	for(i=0;i<M;i++)
		scanf("%d",&favorite_color[i]);
	scanf("%d",&L);
	for(i=0;i<L;i++)
		scanf("%d",&stripe[i]);
	int start=0;
	for(;start<L;start++)
		if(occur(stripe[start],favorite_color,L))
				break;
	if(start>=L) {
		printf("0\n");
		return 0;
	}
	color[start]=favorite_color[start];
	max_len[start]=1;
	int final_max=1;
	int cur_end=favorite_color[start];
	for(i=start+1;i<L;i++) {
		if(stripe[i]==stripe[i-1]) {
			max_len[i]=max_len[i-1]+1;
			if(max_len[i]>final_max)
				final_max=max_len[i];
		} else if(!occur(stripe[i],favorite_color,L)) {
			max_len[i]=max_len[i-1];
		} else if(!occur(stripe[i-1],favorite_color,L)) {
			/*max_len[i]=max_len[i-1]+1;*/
			if(check_after(stripe[i],cur_end,L)) {
				max_len[i]=max_len[i-1]+1;
				cur_end=stripe[i];
			}
			if(max_len[i]>final_max)
				final_max=max_len[i];
		} else if(check_after(stripe[i],cur_end,L)) {
			max_len[i]=max_len[i-1]+1;
			cur_end=stripe[i];
			if(max_len[i]>final_max)
				final_max=max_len[i];
		} else {
			max_len[i]=max_len[i-1];
		}
	}
	printf("%d\n",final_max);
	return 0;
}
