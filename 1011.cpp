#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	double mat[3][3];
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%lf",&mat[i][j]);
	int pos[3],p;
	for(i=0;i<3;i++) {
		int max=-1;
		for(j=0;j<3;j++) {
			if(mat[i][j]>max) {
				max=mat[i][j];
				p=j;
			}
		}
		pos[i]=p;
	}
	double res=1;
	for(i=0;i<3;i++) {
		if(pos[i]==0)
			printf("W ");
		else if(pos[i]==1)
			printf("T ");
		else
			printf("L ");
		res*=mat[i][pos[i]];
	}
	printf("%.2lf\n",(res*0.65-1)*2);
	return 0;
}


