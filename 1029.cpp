#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num1[1000002];
int num2[1000002];
int num_final[20000002];
int main()
{
	int l1,l2,i,j;
	scanf("%d",&l1);
	for(i=0;i<l1;i++)
		scanf("%d",&num1[i]);
	scanf("%d",&l2);
	for(j=0;j<l2;j++)
		scanf("%d",&num2[j]);
	i=j=0;
	int k=0;
	/*for(i<l1&&j<l2) {*/
	while(i<l1&&j<l2) {
		if(num1[i]<num2[j]) {
			num_final[k++]=num1[i];
			i++;
		} else if(num1[i]>num2[j]) {
			num_final[k++]=num2[j];
			j++;
		} else {
			num_final[k++]=num1[i];
			num_final[k++]=num2[j];
			i++;
			j++;
		}
	}
	if(i<l1) {
		while(i<l1) {
			num_final[k++]=num1[i];
			i++;
		}
	}
	if(j<l2) {
		while(j<l2) {
			num_final[k++]=num2[j];
			j++;
		}
	}
	if((l1+l2)%2==0) {
		printf("%d\n",num_final[(l1+l2-1)/2]);
	} else {
		printf("%d\n",num_final[(l1+l2)/2]);
	}
	return 0;
}
