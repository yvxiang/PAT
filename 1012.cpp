#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Student {
	char id[7];
	int score[4];
	int best_rank,best_coures;
}Student;
Student stu[2002];
int N,M;
void find_best_rank_and_coure(int numb)
{
	int best_r=1000000;
	int best_c;
	int i,j;
	for(j=0;j<4;j++) {
		int cur_rank=1;
		for(i=0;i<N;i++) {
			if(stu[i].score[j]>stu[numb].score[j])
				cur_rank++;
		}
		if(cur_rank<best_r) {
			best_r=cur_rank;
			best_c=j;
		}
	}
	stu[numb].best_rank=best_r;
	stu[numb].best_coures=best_c;
}

int main()
{
	scanf("%d%d",&N,&M);
	int i;
	for(i=0;i<N;i++) {
		scanf("%s",stu[i].id);
		int j;
		for(j=1;j<4;j++)
			scanf("%d",&stu[i].score[j]);
		stu[i].score[0]=stu[i].score[1]+stu[i].score[2]+stu[i].score[3];
	}
	for(i=0;i<N;i++) {
		find_best_rank_and_coure(i);
	}
	char id_to_search[7];
	int j;
	for(i=0;i<M;i++) {
		scanf("%s",id_to_search);
		for(j=0;j<N;j++) {
			if(strcmp(id_to_search,stu[j].id)==0) {
				printf("%d ",stu[j].best_rank);
				if(stu[j].best_coures==0)
					printf("A\n");
				else if(stu[j].best_coures==1)
					printf("C\n");
				else if(stu[j].best_coures==2)
					printf("M\n");
				else printf("E\n");
				break;
			}
		}
		if(j==N)
			printf("N/A\n");
	}
	return 0;
}
