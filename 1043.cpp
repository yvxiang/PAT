#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;
int numbers[1002];
int count=0;
typedef struct Node {
	int data;
	Node *lchild;
	Node *rchild;
}*NODE;

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
void create_bst_tree(int s,int e,NODE &root)
{
	if(s>e)
		return ;
	if(!(1<=s&&s<=N)||!(1<=e&&e<=N))
		return ;
	int i;
	root=(NODE)malloc(sizeof(Node));
	root->lchild=NULL;
	root->rchild=NULL;
	root->data=numbers[s];
	for(i=s+1;i<=e;i++)
		if(numbers[i]>numbers[s])
			break;
	create_bst_tree(s+1,i-1,root->lchild);
	create_bst_tree(i,e,root->rchild);
}
void create_mirror_bst_tree(int s,int e,NODE &root)
{
	if(s>e)
		return ;
	if(!(1<=s&&s<=N)||!(1<=e&&e<=N))
		return ;
	int i;
	root=(NODE)malloc(sizeof(Node));
	root->lchild=NULL;
	root->rchild=NULL;
	root->data=numbers[s];
	for(i=s;i<=e;i++)
		if(numbers[i]<numbers[s])
			break;
	create_mirror_bst_tree(s+1,i-1,root->lchild);
	create_mirror_bst_tree(i,e,root->rchild);
}
void post_visited(NODE root)
{
	if(!root)
		return ;
	post_visited(root->lchild);
	post_visited(root->rchild);
	printf("%d",root->data);
	count++;
	if(count==N)
		putchar('\n');
	else
		putchar(' ');
}

int main()
{
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&numbers[i]);
	if(check_bst(1,N)) {
		printf("YES\n");
		NODE root=NULL;
		create_bst_tree(1,N,root);
		post_visited(root);
	} else if(check_mirrot_bst(1,N)) {
		printf("YES\n");
		NODE root=NULL;
		create_mirror_bst_tree(1,N,root);
		post_visited(root);
	} else {
		printf("NO\n");
	}
	return 0;
}
