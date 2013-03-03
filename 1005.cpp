#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;
typedef struct Words {
	char spell[10];
}Words;
Words words[10]={{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"}};
void trans_and_spell_number(char str[])
{
	if(str[0]=='0') {
		printf("zero\n");
		return ;
	}
	stack<int> S;
	int sum=0;
	int i;
	for(i=0;i<strlen(str);i++) {
		sum+=str[i]-'0';
	}
	while(sum) {
		S.push(sum%10);
		sum/=10;
	}
	while(!S.empty()) {
		printf("%s",words[S.top()].spell);
		S.pop();
		if(S.empty())
			putchar('\n');
		else
			putchar(' ');
	}
}
int main()
{
	char N[105];
	scanf("%s",N);
	trans_and_spell_number(N);
	return 0;
}
