#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char number[22];
int occur_src[10]={0};
int occur_dst[10]={0};
void trans(char str[])
{
	char dst[22]={'\0'};
	int i=strlen(str)-1;
	int j=0;
	int c=0;
	for(;i>=0;i--) {
		dst[j]=((str[i]-'0')*2+c)%10+'0';
		c=((str[i]-'0')*2+c)/10;
		j++;
	}
	if(c)
		dst[j]='1';
	else
		j--;
	dst[j+1]='\0';
	i=0;
	for(;j>=0;j--)
		str[i++]=dst[j];
	str[i]='\0';
}
bool check(int src[],int dst[])
{
	int i;
	for(i=0;i<10;i++)
		if(src[i]!=dst[i])
			return false;
	return true;
}
int main()
{
	scanf("%s",number);
	int i;
	for(i=0;i<strlen(number);i++)
		occur_src[number[i]-'0']++;
	trans(number);
	for(i=0;i<strlen(number);i++)
		occur_dst[number[i]-'0']++;
	if(check(occur_src,occur_dst))
		printf("Yes\n");
	else
		printf("No\n");
	puts(number);
	return 0;
}
