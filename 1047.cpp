#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<char *> V[2502];
bool cmp(char name1[],char name2[])
{
	return strcmp(name1,name2)<0;
}
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int i;
	for(i=0;i<N;i++) {
		char *name=new char[5];
		int course_num;
		scanf("%s%d",name,&course_num);
		while(course_num--) {
			int num;
			scanf("%d",&num);
			V[num].push_back(name);
		}
	}
	for(i=1;i<=K;i++)
		sort(V[i].begin(),V[i].end(),cmp);
	for(i=1;i<=K;i++) {
		printf("%d %d\n",i,V[i].size());
		int j;
		for(j=0;j<V[i].size();j++)
			puts(V[i].at(j));
	}
	return 0;
}
