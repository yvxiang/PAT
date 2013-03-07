#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Student {
	char  name[12];
	char sex[2];
	char id[12];
	int grade;
}Student;
Student male;
Student female;
Student temp;
int N;
int main()
{
	int i;
	scanf("%d",&N);
	female.grade=-1;
	male.grade=101;
	for(i=0;i<N;i++) {
		scanf("%s%s%s%d",temp.name,temp.sex,temp.id,&temp.grade);
		if(strcmp(temp.sex,"M")==0) {
			if(temp.grade<male.grade) {
				strcpy(male.name,temp.name);
				strcpy(male.id,temp.id);
				male.grade=temp.grade;
			}
		} else if(strcmp(temp.sex,"F")==0) {
			if(temp.grade>female.grade) {
				strcpy(female.name,temp.name);
				strcpy(female.id,temp.id);
				female.grade=temp.grade;
			}
		}
	}
	if(female.grade!=-1)
		printf("%s %s\n",female.name,female.id);
	else
		printf("Absent\n");
	if(male.grade!=101)
		printf("%s %s\n",male.name,male.id);
	else
		printf("Absent\n");
	if(female.grade!=-1&&male.grade!=101) {
		printf("%d\n",female.grade-male.grade);
	} else {
		printf("NA\n");
	}
	return 0;
}

