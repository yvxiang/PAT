#include <stdio.h>
typedef struct Polynomials {
	int exp;
	double coeff;
}Polynomials;
Polynomials poly_a[1002];
Polynomials poly_b[1002];
double poly_final[2004];
int K1,K2;
int main()
{
	int i,j;
	scanf("%d",&K1);
	for(i=0;i<K1;i++)
		scanf("%d%lf",&poly_a[i].exp,&poly_a[i].coeff);
	scanf("%d",&K2);
	for(i=0;i<K2;i++)
		scanf("%d%lf",&poly_b[i].exp,&poly_b[i].coeff);
	for(i=0;i<=2000;i++)
		poly_final[i]=0;
	for(i=0;i<K1;i++)
		for(j=0;j<K2;j++)
			poly_final[poly_a[i].exp+poly_b[j].exp]+=(poly_a[i].coeff*poly_b[j].coeff);
	int count=0;
	for(i=0;i<=2000;i++)
		if(poly_final[i]!=0)
			count++;
	if(!count) {
		printf("0\n");
		return 0;
	}
	printf("%d",count);
	for(i=2000;i>=0;i--) {
		if(!count)
			break ;
		if(poly_final[i]!=0) {
			printf(" %d %.1lf",i,poly_final[i]);
			count--;
		}
	}
	printf("\n");
	return 0;
}

