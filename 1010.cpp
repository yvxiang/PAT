#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char N1[100],N2[100];
char st[100];
int tag,known_base;
long long trans(char *str,int base)
{
	int i;
	long long res=0;
	for(i=0;i<strlen(str);i++) {
		if(str[i]>='a'&str[i]<='z')
			res=res*base+str[i]-'a'+10;
		else
			res=res*base+str[i]-'0';
	}
	return res;
}
int binary_search(int low,int up,long long  number_to_find)
{
	int mid;
	long long numbers_of_cur_radix;
	while(low<=up) {
		mid=(low+up)/2;
		numbers_of_cur_radix=trans(N2,mid);
		if(numbers_of_cur_radix==number_to_find)
			return mid;
		else if(numbers_of_cur_radix>number_to_find) {
			up=mid-1;
		} else {
			low=mid+1;
		}
	}
	return -1;
}
bool all_zero(char *str)
{
	int i;
	for(i=0;i<strlen(str);i++)
		if(str[i]!='0')
			return false;
	return true;
}

int main()
{
	scanf("%s%s",N1,N2);
	scanf("%d%d",&tag,&known_base);
	if(tag==2) {
		strcpy(st,N1);
		strcpy(N1,N2);
		strcpy(N2,st);
	}//swap N1 and N2 so that the base of N1 is already known.
	int i;
	long long n1,n2;
	n1=trans(N1,known_base);
	if(n1==0) {
		if(!all_zero(N2)) {
			printf("Impossible\n");
		}
		else
			printf("2\n");
		return 0;
	}
	int low=1000,up=-1;
	for(i=0;i<strlen(N2);i++) {
		if(N2[i]>up)
			up=N2[i];
		if(N2[i]<low)
			low=N2[i];
	}
	if(up>='a'&&up<='z')
		up=up-'a'+11;//the max radix.
	else
		up=up-'0'+1;
	if(low>='a'&&low<='z')
		low=low-'a'+11;
	else
		low=low-'0'+1;
	n2=binary_search(up,36,n1);
	if(n2==-1)
		printf("Impossible\n");
	else {
		while(trans(N2,n2)==n1)
			n2--;
		printf("%lld\n",n2+1);
	}

	return 0;
}
