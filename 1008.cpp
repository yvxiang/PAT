#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int N;
	int i,cur_floor,next_floor;
	int sum=0;
	scanf("%d",&N);
	cur_floor=0;
	for(i=0;i<N;i++) {
		scanf("%d",&next_floor);
		if(next_floor>cur_floor) {
			sum+=6*(next_floor-cur_floor);
		} else {
			sum+=4*(cur_floor-next_floor);
		}
		cur_floor=next_floor;
	}
	sum+=N*5;
	printf("%d\n",sum);
	return 0;
}
	
