#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int N,M;
	int numbers[100002];
	int i,j;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
		scanf("%d",&numbers[i]);
	sort(numbers,numbers+N);
	i=0;
	j=N-1;
	while(i<j) {
		if(numbers[i]+numbers[j]==M) {
			printf("%d %d\n",numbers[i],numbers[j]);
			break;
		} else if(numbers[i]+numbers[j]>M) {
			j--;
		} else if(numbers[i]+numbers[j]<M) {
			i++;
		}
	}
	if(i>=j)
		printf("No Solution\n");
	return 0;
}
