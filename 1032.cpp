#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
	char data;
	int next_address;
}Node;
Node nodes[100002];
int main()
{
	int start1,start2,nodes_number;
	scanf("%d%d%d",&start1,&start2,&nodes_number);
	int i;
	int a,next;
	char d;
	for(i=0;i<nodes_number;i++) {
		scanf("%d %c %d",&a,&d,&next);
		nodes[a].data=d;
		nodes[a].next_address=next;
	}
	int cur=start1;
	int l1=0;
	while(cur!=-1) {
		l1++;
		cur=nodes[cur].next_address;
	}
	int l2=0;
	cur=start2;
	while(cur!=-1) {
		l2++;
		cur=nodes[cur].next_address;
	}
	if(l1>l2) {
		int cut=l1-l2;
		int count;
		for(count=1;count<=cut;count++)
			start1=nodes[start1].next_address;
	} else if(l2>l1) {
		int cut=l2-l1;
		int count;
		for(count=1;count<=cut;count++)
			start2=nodes[start2].next_address;
	}//now allgned
	while(start1!=-1&&start2!=-1) {
	    if(start1==start2) {
			printf("%05d\n",start1);
			break;
		} else {
			start1=nodes[start1].next_address;
			start2=nodes[start2].next_address;
		}
	}
	if(start1==-1&&start2==-1)
		printf("-1\n");
	return 0;
}
