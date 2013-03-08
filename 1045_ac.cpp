#include <stdio.h>
int n,m,l;
int main()
{
	int favorite_color[202]={0};
	int stripe[10002]={0};
	int dp[10002]={0};
	scanf("%d",&n);
	scanf("%d",&m);
	int i;
	int color;
	for(i=1;i<=m;i++) {
		scanf("%d",&color);
		if(color<=n)
			favorite_color[color]=i;
	}
	scanf("%d",&l);
	int len=0;
	for(i=0;i<l;i++) {
		scanf("%d",&color);
		if(color<=n&&favorite_color[color]!=0)
			stripe[len++]=favorite_color[color];
	}
	int j;
	/*for(j=0;j<len;j++)*/
		/*printf("%5d",stripe[j]);*/
	int max_final=-1;
	for(i=0;i<len;i++) {
		dp[i]=1;
		for(j=0;j<i;j++) {
			if(stripe[i]>=stripe[j]&&dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
		}
		if(dp[i]>max_final)
			max_final=dp[i];
	}
	printf("%d\n",max_final);
	return 0;
}
		

