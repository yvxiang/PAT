#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct Student {
	char id_nubmer[16];
	char sign_in_time[20];
   	char sign_out_time[20];
}Student;
Student s[2];
int N;
int main()
{
	scanf("%d",&N);
	scanf("%s%s%s",s[0].id_nubmer,s[0].sign_in_time,s[0].sign_out_time);
	char min[20],max[20];
	char min_id[16];
	char max_id[16];
	strcpy(min,s[0].sign_in_time);
	strcpy(max,s[0].sign_out_time);
	strcpy(min_id,s[0].id_nubmer);
	strcpy(max_id,s[0].id_nubmer);
	int i;
	for(i=1;i<N;i++) {
		scanf("%s%s%s",s[1].id_nubmer,s[1].sign_in_time,s[1].sign_out_time);
		if(strcmp(s[1].sign_in_time,min)<0) {
			strcpy(min,s[1].sign_in_time);
			strcpy(min_id,s[1].id_nubmer);
		}
		if(strcmp(s[1].sign_out_time,max)>0) {
			strcpy(max,s[1].sign_out_time);
			strcpy(max_id,s[1].id_nubmer);
		}
	}
	printf("%s %s\n",min_id,max_id);
	return 0;
}



	
