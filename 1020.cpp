#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
int N;
int postorder[102];
int inorder[102];
typedef struct Node {
	int data;
	Node *lchild;
	Node *rchild;
}*NODE;
int find_pos_in_inorder(int num)
{
	int i;
	for(i=1;i<=N;i++)
		if(inorder[i]==num)
			return i;
	return -1;
}
void create(int post_start,int post_end,int in_start,int in_end,NODE &root)
{
	if(post_start>post_end||in_start>in_end)
		return ;
	root=(NODE)malloc(sizeof(Node));
	root->data=postorder[post_end];
	root->lchild=root->rchild=NULL;
	int pos=find_pos_in_inorder(postorder[post_end]);
	if(pos==-1)
		return ;
	create(post_start,post_start+pos-in_start-1,in_start,pos-1,root->lchild);
	create(post_start+pos-in_start,post_end-1,pos+1,in_end,root->rchild);
}
void level_travel(NODE root)
{
	if(!root) 
		return ;
	int count=0;
	queue<NODE> Q;
	Q.push(root);
	NODE cur_node;
	while(!Q.empty()) {
		cur_node=Q.front();
		Q.pop();
		printf("%d",cur_node->data);
		count++;
		if(count==N)
			putchar('\n');
		else
			putchar(' ');
		if(cur_node->lchild)
			Q.push(cur_node->lchild);
		if(cur_node->rchild)
			Q.push(cur_node->rchild);
	}
}

int main()
{
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&postorder[i]);
	for(i=1;i<=N;i++)
		scanf("%d",&inorder[i]);
	NODE root=NULL;
	create(1,N,1,N,root);
	level_travel(root);
	return 0;
}
