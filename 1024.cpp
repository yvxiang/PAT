#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str_src[1002];
char str_dst[1002];
void gets_num(char str[])
{
	char st[1002]={'\0'};
	int i=0,j=strlen(str)-1;
	for(i=0;i<strlen(str);i++)
		st[j--]=str[i];

	j=0;//copy is over
	char resu[1002]={'\0'};
	int c=0;
	for(i=strlen(str)-1;i>=0;i--) {
		resu[j]=(st[i]-'0'+str[i]-'0'+c)%10+'0';
		c=(st[i]-'0'+str[i]-'0'+c)/10;
		j++;
	}
	j--;
	if(c) {
		str[0]='1';
		i=1;
	} else {
		i=0;
	}
	for(;j>=0;j--)
		str[i++]=resu[j];
	str[i]='\0';
}
bool check(char str[])
{
	char dst[1002]={'\0'};
	int i,j=0;
	for(i=strlen(str)-1;i>=0;i--) {
		dst[j++]=str[i];
	}
	return strcmp(str,dst)==0;
}

int main()
{
	int K;
	scanf("%s%d",str_src,&K);
	int i;
	if(str_src[0]=='0') {
		printf("0\n0\n");
		return 0;
	}
	if(check(str_src)) {
			puts(str_src);
			printf("0\n");
			return 0;
	}
	for(i=1;i<=K;i++) {
		gets_num(str_src);//result is in str_ds
		if(check(str_src)) {
			puts(str_src);
			printf("%d\n",i);
			return 0;
		}
	}
	puts(str_src);
	printf("%d\n",K);
	return 0;
}
		

