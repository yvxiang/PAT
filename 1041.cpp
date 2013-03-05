#include <stdio.h>
#include <stdlib.h>
int numbers[100002];
int occur[10002]={0};
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) {
		scanf("%d",&numbers[i]);
		occur[numbers[i]]++;
	}
	for(i=0;i<n;i++)
		if(occur[numbers[i]]==1) {
			printf("%d\n",numbers[i]);
			return 0;
		}
	printf("None\n");
	return 0;
}
