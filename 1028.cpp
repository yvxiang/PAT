#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct Student {
	char id[7];
	char name[9];
	int grade;
}Student;
Student stus[100002];
int N,C;
bool cmp(Student a,Student b)
{
	if(C==1) {
		return strcmp(a.id,b.id)<0;
	} else if(C==2) {
		if(strcmp(a.name,b.name)!=0)
			return strcmp(a.name,b.name)<0;
		else
			return strcmp(a.id,b.id)<0;
	} else if(C==3) {
		if(a.grade!=b.grade)
			return a.grade<b.grade;
		else
			return strcmp(a.id,b.id)<0;
	}
}
void out_put()
{
	int i;
	for(i=0;i<N;i++)
		printf("%s %s %d\n",stus[i].id,stus[i].name,stus[i].grade);
}
int main()
{
	scanf("%d%d",&N,&C);
	int i;
	for(i=0;i<N;i++)
		scanf("%s%s%d",stus[i].id,stus[i].name,&stus[i].grade);
//	out_put();
	sort(stus,stus+N,cmp);
	for(i=0;i<N;i++)
		printf("%s %s %d\n",stus[i].id,stus[i].name,stus[i].grade);
	return 0;
}

