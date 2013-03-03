#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct Polynomials {
	int exp;
	double tie;
}Polynomials;
Polynomials poly_a[12];
Polynomials poly_b[12];
int K1,K2;
double final[1002];
bool cmp(Polynomials a,Polynomials b)
{
	return a.exp<b.exp;
}
int main()
{
	scanf("%d",&K1);
	int i;
	for(i=0;i<1002;i++)
		final[i]=0;
	for(i=0;i<K1;i++)
		scanf("%d%lf",&poly_a[i].exp,&poly_a[i].tie);
	scanf("%d",&K2);
	for(i=0;i<K2;i++)
		scanf("%d%lf",&poly_b[i].exp,&poly_b[i].tie);
	sort(poly_a,poly_a+K1,cmp);
	sort(poly_b,poly_b+K2,cmp);
	int j;
	i=j=0;
	while(i!=K1&&j!=K2) {
		if(poly_a[i].exp==poly_b[j].exp) {
			final[poly_a[i].exp]=poly_a[i].tie+poly_b[j].tie;
			i++;
			j++;
		} else if(poly_a[i].exp<poly_b[j].exp) {
			final[poly_a[i].exp]=poly_a[i].tie;
			i++;
		} else {
			final[poly_b[j].exp]=poly_b[j].tie;
			j++;
		}
	}
	if(i!=K1) {
		while(i!=K1) {
			final[poly_a[i].exp]=poly_a[i].tie;
			i++;
		}
	}
	if(j!=K2) {
		while(j!=K2) {
			final[poly_b[j].exp]=poly_b[j].tie;
			j++;
		}
	}
	int count=0;
	for(i=0;i<=1000;i++) {
		if(final[i]!=0) {
			count++;
		}
	}
	printf("%d",count);
	i=1000;
	while(!(i<0)) {
		if(final[i]==0)
			i--;
		else {
			printf(" %d %.1lf",i,final[i]);
			i--;
			count--;
			if(count==0)
				break;
		}
	}
	printf("\n");
}


