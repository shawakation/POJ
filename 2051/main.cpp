#include <cstdio>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;
struct task {
	int id,period,timet;
	task():id(0),period(0),timet(0) {}
	task(int a,int b):id(a),period(b),timet(b) {}
	friend bool operator < (const task& a,const task& b) {
		if(a.period!=b.period) return a.period<b.period;
		else return a.id<b.id;
	}
};
deque<task> tasks;
void downadjust(int l,int r)
{
	int i=l,j=i*2;
	while(j<=r) {
		if(j+1<=r&&tasks[j+1]<tasks[j]) j++;
		if(tasks[i]<tasks[j]) break;
		else {
			swap(tasks[i],tasks[j]);
			i=j;
			j=i*2;
		}
	}
}
void createheap(int n)
{
	for(int i=n/2; i>=1; i--) downadjust(i,n);
}
int main()
{
	int k;
	char order[10];
	while(1) {
		scanf("%s",order);
		if(strcmp(order,"#")==0) break;
		else {
			int num,t;
			scanf("%d%d",&num,&t);
			tasks.push_back(task(num,t));
		}
	}
	tasks.push_front(task());
	int n=tasks.size()-1;
	createheap(n);
	scanf("%d",&k);
	while(k--) {
		printf("%d\n",tasks[1].id);
		tasks[1].period+=tasks[1].timet;
		downadjust(1,n);
	}
	return 0;
}
