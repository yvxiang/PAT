#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;
void trans(int n)
{
	if(n==0) {
		printf("0\n");
		return ;
	}
	if(n<0) {
		putchar('-');
		n*=-1;
	}
	stack<char> S;
	int count=0;
	while(n) {
		S.push((n%10)+'0');
		n/=10;
		count++;
		if(count==3&&n) {
			S.push(',');
			count=0;
		}
	}
	while(!S.empty()) {
		putchar(S.top());
		S.pop();
	}
	putchar('\n');
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	trans(a+b);
	return 0;
}
