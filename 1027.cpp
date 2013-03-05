#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
void trans_and_output(int color)
{
	if(!color) {
		printf("00");
		return ;
	}
	stack<char> S;
	char ch;
	while(color) {
		if(color%13>9) {
			ch=color%13-10+'A';
		} else {
			ch=color%13+'0';
		}
		S.push(ch);
		color/=13;
	}
	if(S.size()==1)
		S.push('0');
	while(!S.empty()) {
		putchar(S.top());
		S.pop();
	}
}
int main()
{
	int numbers[3];
	int i;
	for(i=0;i<3;i++)
		scanf("%d",&numbers[i]);
	putchar('#');
	for(i=0;i<3;i++)
		trans_and_output(numbers[i]);
	putchar('\n');
	return 0;
}
