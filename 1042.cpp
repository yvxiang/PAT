#include <stdio.h>
#include <string.h>
int ori_array[60];
int dst_array[60];
int order_array[60];
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<60;i++)
		ori_array[i]=i;
	for(i=1;i<=54;i++)
		scanf("%d",&order_array[i]);
	while(t--) {
		for(i=1;i<=54;i++) {
			dst_array[order_array[i]]=ori_array[i];
		}
		for(i=1;i<=54;i++) 
			ori_array[i]=dst_array[i];
	}
	for(i=1;i<=54;i++) {
		if((ori_array[i]-1)/13==0) {
			putchar('S');
			printf("%d",ori_array[i]%13==0?13:ori_array[i]%13);
		} else if((ori_array[i]-1)/13==1) {
			putchar('H');
			printf("%d",ori_array[i]%13==0?13:ori_array[i]%13);
		} else if((ori_array[i]-1)/13==2) {
			putchar('C');
			printf("%d",ori_array[i]%13==0?13:ori_array[i]%13);
		} else if((ori_array[i]-1)/13==3) {
			putchar('D');
			printf("%d",ori_array[i]%13==0?13:ori_array[i]%13);
		} else if(ori_array[i]>=53) {
			putchar('J');
			printf("%d",ori_array[i]%13);
		}
		if(i==54)
			putchar('\n');
		else
			putchar(' ');
	}
	return 0;
}

				


