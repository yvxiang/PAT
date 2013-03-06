#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct Window {
	int next_free_time;
}Window;
Window w[102];
typedef struct Customer {
	int arrive_time;
	int process_time;
	int start_time;
}Customer;
Customer customers[10002];
int N,K;
bool cmp(Customer a,Customer b)
{
	return a.arrive_time<b.arrive_time;
}
int find_avail_window(int c)
{
	int i;
	for(i=0;i<K;i++) {
		if(w[i].next_free_time<=customers[c].arrive_time)
			return i;
	}
	return -1;
}
int find_fatest_window()
{
	int i;
	int ft=w[0].next_free_time;
	int pos=0;
	for(i=1;i<K;i++) {
		if(w[i].next_free_time<ft) {
			ft=w[i].next_free_time;
			pos=i;
		}
	}
	return pos;
}

int main()
{
	scanf("%d%d",&N,&K);
	int i;
	char time[20];
	int t;
	int total_wait_time=0;
	for(i=0;i<K;i++)
		w[i].next_free_time=8*3600;
	for(i=0;i<N;i++) {
		int h,m,s;
		scanf("%s%d",time,&t);
		sscanf(time,"%d:%d:%d",&h,&m,&s);
		customers[i].arrive_time=h*3600+m*60+s;
		if(customers[i].arrive_time<8*3600) {
			total_wait_time+=8*3600-customers[i].arrive_time;
		}
		customers[i].process_time=t*60;
	}
	sort(customers,customers+N,cmp);
	for(i=0;i<N;i++) {
		int pos=find_avail_window(i);
		if(pos>=0) {//不需要等
			if(customers[i].arrive_time<8*3600)
				w[pos].next_free_time=8*3600+customers[i].process_time;
			else
				w[pos].next_free_time+=customers[i].arrive_time+customers[i].process_time;
		} else {
			pos=find_fatest_window();
			if(customers[i].arrive_time<8*3600) {
				total_wait_time+=w[pos].next_free_time-8*3600;
				/*printf("%d\n",total_wait_time);*/
				w[pos].next_free_time+=customers[i].process_time;
			} else {
				total_wait_time+=w[pos].next_free_time-customers[i].arrive_time;
				/*printf("%d\n",total_wait_time);*/
				w[pos].next_free_time+=customers[i].process_time;
			}
		}	   
	}
	/*printf("%d\n",total_wait_time);*/
	printf("%.1lf\n",(double)total_wait_time/i/60.0);
	return 0;
}
