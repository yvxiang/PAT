#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
int N,M,K,Q;// N windows ,M maximun capacity  K, customers ,Q queries;
int process_time_of_customers[1002];
int start_time_of_customers[1002];
int end_time_of_customers[1002];
bool visited[1002]={false};
typedef struct Windows {
	int free_time;
	queue<int> wait_in_this_window;
}Windows;
Windows win[22];
int find_earliest()
{
	int ft=0x0fffffff;
	int i,pos;
	for(i=1;i<=N;i++)
		//if(win[i].ft<ft) {
		if(win[i].free_time+process_time_of_customers[win[i].wait_in_this_window.front()]<ft) {
			ft=win[i].free_time+process_time_of_customers[win[i].wait_in_this_window.front()];
			pos=i;
		}
	return pos;
}
int find_shortest()
{
	int np=0x0fffffff;
	int i,pos;
	for(i=1;i<=N;i++) 
		if(win[i].wait_in_this_window.size()<np) {
		/*if(win[i].wait_in_this_window.empty()||((!win[i].wait_in_this_window.empty())&&win[i].wait_in_this_window.size()<np)) {*/
			if(win[i].wait_in_this_window.empty())
				np=0;
			else
				np=win[i].wait_in_this_window.size();
			pos=i;
		}
	return pos;
}
bool all_full()
{
	int i;
	for(i=1;i<=N;i++)
		/*if(!win[i].wait_in_this_window.empty()&&win[i].wait_in_this_window.size()<M||win[i].wait_in_this_window.empty())*/
		if(((!win[i].wait_in_this_window.empty())&&win[i].wait_in_this_window.size()<M)||win[i].wait_in_this_window.empty())
			return false;
	return true;
}
int find_fatest_window()
{
	if(all_full()) 
		return -1;
	else
		return find_shortest();
}
void free_the_earliest()
{
	int pos=find_earliest();
	end_time_of_customers[win[pos].wait_in_this_window.front()]=win[pos].free_time+process_time_of_customers[win[pos].wait_in_this_window.front()];
	win[pos].free_time=end_time_of_customers[win[pos].wait_in_this_window.front()];
	win[pos].wait_in_this_window.pop();
}
void calc()
{
	int i;
	for(i=1;i<=K;i++) {
		if(!visited[i]) {
			int pos_to_wait=find_fatest_window();
			if(pos_to_wait==-1) {
				free_the_earliest();
				return ;
			}
			else {
				win[pos_to_wait].wait_in_this_window.push(i);
				visited[i]=true;
			}
		}
	}
}
bool check(int tim)
{
	if(tim/60>=17)
		return false;
	return true;
}
bool all_process()
{
	int i;
	for(i=1;i<=K;i++) {
		if(!visited[i])
			return false;
	}
	return true;
}
int main()
{
	int i;
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	for(i=1;i<=N;i++) {
		win[i].free_time=8*60;
		/*win[i].wait_in_this_window.clean();*/
		while(!win[i].wait_in_this_window.empty())
			win[i].wait_in_this_window.pop();
	}
	for(i=1;i<=K;i++) 
		scanf("%d",&process_time_of_customers[i]);
	while(!all_process())
		calc();
	for(i=1;i<=N;i++) {
		while(!win[i].wait_in_this_window.empty()) {
			start_time_of_customers[win[i].wait_in_this_window.front()]=win[i].free_time;
			end_time_of_customers[win[i].wait_in_this_window.front()]=win[i].free_time+process_time_of_customers[win[i].wait_in_this_window.front()];
			win[i].free_time=end_time_of_customers[win[i].wait_in_this_window.front()];
			win[i].wait_in_this_window.pop();
		}
	}
	int num_to_query;
	for(i=0;i<Q;i++) {
		scanf("%d",&num_to_query);
		if(check(start_time_of_customers[num_to_query]))
		/*if(check(end_time_of_customers[num_to_query]))*/
			printf("%02d:%02d\n",end_time_of_customers[num_to_query]/60,end_time_of_customers[num_to_query]%60);
		else
			printf("Sorry\n");
	}
	return 0;
}
