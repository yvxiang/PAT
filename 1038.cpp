#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct Words {
	char spell[9];
}Words;
Words words[10002];
bool cmp(Words a,Words b)
{
	char left[20];
	char right[20];
	strcpy(left,a.spell);
	char *pos=left+strlen(a.spell);
	strcpy(pos,b.spell);
	strcpy(right,b.spell);
	pos=right+strlen(b.spell);
	strcpy(pos,a.spell);
	return strcmp(left,right)<0;
}
bool check_all_zero(char str[])
{
	char *p=str;
	while(*p) {
		if(*p!='0')
			return false;
		p++;
	}
	return true;
}
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	int i;
	for(i=0;i<N;i++)
		scanf("%s",words[i].spell);
	sort(words,words+N,cmp);
	char *p=words[0].spell;
	if(check_all_zero(words[0].spell)) {
		puts("0\n");
		return 0;
	}
	while(*p=='0')
		p++;
	while(*p) {
		putchar(*p);
		p++;
	}
	for(i=1;i<N;i++)
		printf("%s",words[i].spell);
	putchar('\n');
	return 0;
}

