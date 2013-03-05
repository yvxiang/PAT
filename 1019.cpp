#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;
int N,b;
bool check(int src[],int dst[],int len)
{
	int i;
	for(i=0;i<=len;i++)
		if(src[i]!=dst[i])
			return false;
	return true;
}
void trans_and_track_and_output(int num,int bas)
{
	int num_src[10002];
	int num_dst[10002];
	int i=0,j;
	while(num) {
		num_src[i++]=num%bas;
		num/=bas;
	}
	i--;
	int len=i;
	for(j=0;j<=len;j++)
		num_dst[j]=num_src[i--];
	if(check(num_src,num_dst,len))
		printf("Yes\n");
	else
		printf("No\n");
	for(i=0;i<=len;i++) {
		printf("%d",num_dst[i]);
		if(i==len)
			putchar('\n');
		else
			putchar(' ');
	}
}
	

int main()
{
	scanf("%d%d",&N,&b);
	if(N==0) {
		printf("Yes\n");
		printf("0\n");
		return 0;
	}
	trans_and_track_and_output(N,b);
	return 0;
}
