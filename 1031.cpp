#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char str[102];
bool check(int height)
{
	int bottom_l=strlen(str)-2*height+2;

	/*if(((strlen(str)-2*height+2)>=3)&&height<=(strlen(str)-2*height+2)) */
	if(bottom_l>=3&&height<=bottom_l)
		return true;
	return false;
}
int main()
{
	scanf("%s",str);
	int height=strlen(str);
	while(1) {
		/*if(((strlen(str)-2*height+2)>=3)&&height<=(strlen(str)-2*height+2)) {*/
		if(check(height)) {
			break;
		}
		height--;
	}
	int space=strlen(str)-2*height;
	int i;
	char *p=str;
	char *q=str+strlen(str)-1;
	for(i=1;i<height;i++) {
		putchar(*p);
		int j;
		for(j=1;j<=space;j++)
			putchar(' ');
		putchar(*q);
		p++;
		q--;
		putchar('\n');
	}
	while(p<=q) {
		putchar(*p);
		p++;
	}
	putchar('\n');
	return 0;
}
