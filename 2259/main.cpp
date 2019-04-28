#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 1000000
#define maxt 1001
using namespace std;
queue<int> teams[maxt],teamorder;
int teamnum[maxn];
bool ishave[maxt];
void enqueue(int n)
{
	int t=teamnum[n];
	if(!ishave[t]) {
		ishave[t]=1;
		teamorder.push(t);
	}
	teams[t].push(n);
}
int dequeue()
{
	int t=teamorder.front();
	int tt=teams[t].front();
	teams[t].pop();
	if(teams[t].empty()) {
		ishave[t]=0;
		teamorder.pop();
	}
	return tt;
}
int main()
{
	int t,h=1;
	while(1) {
		scanf("%d",&t);
		if(t==0) break;
		memset(teamnum,0,sizeof(teamnum));
		for(int i=1; i<=t; i++) {
			ishave[i]=0;
			while(!teams[i].empty()) teams[i].pop();
		}
		while(!teamorder.empty()) teamorder.pop();
		for(int i=1; i<=t; i++) {
			int n;
			scanf("%d",&n);
			for(int j=0; j<n; j++) {
				int id;
				scanf("%d",&id);
				teamnum[id]=i;
			}
		}
		char order[10];
		printf("Scenario #%d\n",h++);
		while(1) {
			scanf("%s",order);
			if(strcmp(order,"STOP")==0) break;
			if(strcmp(order,"ENQUEUE")==0) {
				int id;
				scanf("%d",&id);
				enqueue(id);
			} else if(strcmp(order,"DEQUEUE")==0) printf("%d\n",dequeue());
		}
		puts("");
	}
	return 0;
}
