#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;
int reverse(int n,int radix)
{
	if(n==0)
		return 0;
	int res=0;
	while(n) {
		res=res*radix+n%radix;
		n/=radix;
	}
	return res;
}
bool prime(int n)
{
	if(n<2)
		return false;
	if(n==2)
		return true;
	int i;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	int N,D;
	while(scanf("%d",&N)!=EOF) {
		if(N<0)
			return 0;
		scanf("%d",&D);
		if(!prime(N)) {
			printf("No\n");
			continue;
		}
		int rev=reverse(N,D);
		if(prime(rev))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
