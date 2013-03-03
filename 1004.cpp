#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <list>
using namespace std;
typedef struct Node {
	int child_number;
	list<int> l;
}Node;
Node node[1002];
bool flag=true;
void check_leave_for_every_level()
{
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()) {
		int cur_level_count=Q.size();
		int i,cur_node;
		int cur_count=0;
		for(i=0;i<cur_level_count;i++) {
			cur_node=Q.front();
			Q.pop();
			if(node[cur_node].l.size()==0) {
				cur_count++;
			} else {
				while(node[cur_node].l.size()!=0) {
					Q.push(node[cur_node].l.front());
					node[cur_node].l.pop_front();
				}
			}
		}
		if(!flag)
			printf(" ");
		if(flag)
			flag=false;
		printf("%d",cur_count);
	}
	printf("\n");
}
int N,M;
int main()
{
	scanf("%d%d",&N,&M);
	int i,j,node_number,child_count,child_number;
	for(i=0;i<M;i++) {
		scanf("%d%d",&node_number,&child_count);
		node[node_number].child_number=child_count;
		for(j=0;j<child_count;j++) {
			scanf("%d",&child_number);
			node[node_number].l.push_back(child_number);
		}
	}//input is over
	check_leave_for_every_level();
	return 0;
}
