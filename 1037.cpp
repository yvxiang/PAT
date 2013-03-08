#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n1,n2;
	int numbers1[100002];
	int numbers2[100002];
	scanf("%d",&n1);
	int i,j;
	for(i=0;i<n1;i++)
		scanf("%d",&numbers1[i]);
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
		scanf("%d",&numbers2[i]);
	sort(numbers1,numbers1+n1,cmp);
	sort(numbers2,numbers2+n2,cmp);
	int total=0;
	i=j=0;
	/*for(i<n1&&j<n2&&numbers1[i]>=0&&numbers2[j]>=0) {*/
	while((i<n1&&j<n2)&&(numbers1[i]>=0&&numbers2[j]>=0)) {
		total+=numbers1[i]*numbers2[j];
		i++;
		j++;
	}
	i=n1-1;
	j=n2-1;
	while(i>=0&&j>=0&&numbers1[i]<=0&&numbers2[j]<=0) {
		total+=numbers1[i]*numbers2[j];
		i--;
		j--;
	}
	printf("%d\n",total);
	return 0;
}
