#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct Customer {
	int arrive_time;
	int process_time;
}Customer;
Customer customers[10002];
typedef struct Window {
	int next_free_time;
}Window;
Window w[102];
int N,K;
int find_avail_window(int ti)
{
	int i;
	for(i=0;i<K;i++)
		if(w[i].next_free_time<=ti)
			return i;
	return -1;
}
int find_fatest_window()
{
	int i;
	int e=0;
	for(i=1;i<K;i++)
		if(w[i].next_free_time<w[e].next_free_time)
			e=i;
	return e;
}
bool cmp(Customer a,Customer b)
{
	return a.arrive_time<b.arrive_time;
}
int main()
{
	scanf("%d%d",&N,&K);
	int i;
	for(i=0;i<K;i++)
		w[i].next_free_time=8*3600;
	char time[100];
	int t;
	int total_wait_time=0;
	int len=0;
	for(i=0;i<N;i++) {
		scanf("%s%d",time,&t);
		int h,m,s;
		if(strcmp(time,"17:00:00")>0)
			continue;
		sscanf(time,"%d:%d:%d",&h,&m,&s);
		if(h<8)
			total_wait_time+=8*3600-(3600*h+60*m+s);
		customers[len].arrive_time=3600*h+m*60+s;
		customers[len++].process_time=t*60;
	}
	N=len;
	sort(customers,customers+N,cmp);
	/*printf("%d\n",total_wait_time);*/
	for(i=0;i<N;i++) {
		int pos=find_avail_window(customers[i].arrive_time);
		if(pos>=0) {//不需要等 
			if(customers[i].arrive_time<8*3600) {
				w[pos].next_free_time=8*3600+customers[i].process_time;
			} else {
				w[pos].next_free_time=customers[i].arrive_time+customers[i].process_time;
			}
		} else {
			pos=find_fatest_window();
			if(customers[i].arrive_time<8*3600) {
				total_wait_time+=w[pos].next_free_time-8*3600;
				/*printf("%d\n",total_wait_time);*/
				w[pos].next_free_time=w[pos].next_free_time+customers[i].process_time;
			} else {
				total_wait_time+=w[pos].next_free_time-customers[i].arrive_time;
				/*printf("%d\n",total_wait_time);*/
				w[pos].next_free_time=w[pos].next_free_time+customers[i].process_time;
			}
		}
	}
	printf("%.1lf\n",total_wait_time*1.0/60.0/N);
	return 0;
}
