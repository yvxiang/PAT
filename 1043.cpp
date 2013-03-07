#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;
int N;
int numbers[1002];
stack<int> S;
bool check_bst(int start,int end)
{
	if(start>end)
		return true;
	if(start==end)
		return true;
	int i;
	for(i=start+1;i<=end;i++)
		if(numbers[i]>=numbers[start])
			break;
	int pos=i;
	for(;i<=end;i++) 
		if(numbers[i]<numbers[start])
			return false;
	return check_bst(start+1,pos)&&check_bst(pos+1,end);
}
bool check_mirrot_bst(int start,int end)
{
	if(start>end)
		return true;
	if(start==end)
		return true;
	int i;
	for(i=start+1;i<=end;i++)
		if(numbers[i]<numbers[start])
			break;
	int pos=i;
	for(;i<=end;i++)
		if(numbers[i]>=numbers[start])
			return false;
	return check_mirrot_bst(start+1,pos)&&check_mirrot_bst(pos+1,end);
}
void post_visited_bst(int s,int e)
{
/*	if(!root)
		return ;
	post_visited(root->lchild);
	post_visited(root->rchild);
	printf("%d",root->data);
	count++;
	if(count==N)
		putchar('\n');
	else
		putchar(' ');
*/
	if(s>e)
		return ;
	if(s==e) {
		S.push(numbers[s]);
		return ;
	}
	S.push(numbers[s]);
	int i;
	for(i=s+1;i<=e;i++)
		if(numbers[i]>=numbers[s])
			break;
	post_visited_bst(i,e);
	post_visited_bst(s+1,i-1);

}
void post_visited_mirror_bst(int s,int e)
{
	if(s>e)
		return ;
	if(s==e) {
		S.push(numbers[s]);
		return ;
	}
	S.push(numbers[s]);
	int i;
	for(i=s+1;i<=e;i++)
		if(numbers[i]<numbers[s])
			break;
	post_visited_mirror_bst(i,e);
	post_visited_mirror_bst(s+1,i-1);
}


int main()
{
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&numbers[i]);
	if(check_bst(1,N)) {
		printf("YES\n");
		post_visited_bst(1,N);
		while(!S.empty()) {
			printf("%d",S.top());
			S.pop();
			if(!S.empty())
				putchar(' ');
			else
				putchar('\n');
		}
	} else if(check_mirrot_bst(1,N)) {
		printf("YES\n");
		post_visited_mirror_bst(1,N);
		while(!S.empty()) {
			printf("%d",S.top());
			S.pop();
			if(!S.empty()) 
				putchar(' ');
			else
				putchar('\n');
		}
	} else {
		printf("NO\n");
	}
	return 0;
}
