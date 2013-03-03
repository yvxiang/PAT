#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int numbers[10003];
	int sum[10003];
	bool flag=false;
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) {
		scanf("%d",&numbers[i]);
		if(numbers[i]>=0)
			flag=true;
	}
	int max_sum=numbers[0];
	int final_start,final_end,cur_start,cur_end;
	sum[0]=numbers[0];
	if(!flag) {
		printf("0 %d %d\n",numbers[0],numbers[n-1]);
		return 0;
	} else {
		final_start=final_start=cur_start=cur_start=0;
		for(i=1;i<n;i++) {
			if(sum[i-1]>0) {
				sum[i]=sum[i-1]+numbers[i];
				cur_end=i;
				if(sum[i]>max_sum) {
					max_sum=sum[i];
					final_start=cur_start;
					final_end=cur_end;
				}
			} else {
				sum[i]=numbers[i];
				cur_start=i;
				cur_end=i;
				if(sum[i]>max_sum) {
					final_start=i;
					final_end=i;
					max_sum=sum[i];
				}
			}
		}
	}
	printf("%d %d %d\n",max_sum,numbers[final_start],numbers[final_end]);
	return 0;
}

