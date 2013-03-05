#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
typedef struct Team {
	char user_name[21];
	char password[21];
	bool change;
}Team;
Team team[1002];
bool check(char str[])
{
	int i;
	bool flag=false;
	for(i=0;i<strlen(str);i++) {
		if(str[i]=='1') {
			str[i]='@';
			flag=true;
		} else if(str[i]=='0') {
			str[i]='%';
			flag=true;
		} else if(str[i]=='l') {
			str[i]='L';
			flag=true;
		} else if(str[i]=='O') {
			str[i]='o';
			flag=true;
		}
	}
	return flag;
}
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++)
		scanf("%s%s",team[i].user_name,team[i].password);
	int count=0;
	for(i=0;i<N;i++)
		if(check(team[i].password)) {
			team[i].change=true;
			count++;
		} else {
			team[i].change=false;
		}
	if(count==0) {
		if(N>1)
			printf("There are %d accounts and no account is modified\n",N);
		else
			printf("There is %d account and no account is modified\n",N);
	} else {
		printf("%d\n",count);
		for(i=0;i<N;i++)
			if(team[i].change)
				printf("%s %s\n",team[i].user_name,team[i].password);
	}
	return 0;
}
