#include <cstdio>
#define maxn 100002
using namespace std;
int father[maxn];
bool rela[maxn];
void init(int n)
{
	for(int i=1; i<=n; i++) {
		father[i]=i;
		rela[i]=0;
	}
}
int find(int x)
{
	int t=father[x];
	if(x==father[x]) return x;
	father[x]=find(father[x]);
	rela[x]=(rela[x]==rela[t])?0:1;
	return father[x];
}
void unit(int a,int b,int fa,int fb)
{
	if(fa!=fb) {
		father[fa]=fb;
		rela[fa]=(rela[a]==rela[b])?1:0;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m;
		scanf("%d%d",&n,&m);
		init(n);
		while(m--) {
			getchar();
			char c;
			int a,b;
			scanf("%c %d %d",&c,&a,&b);
			int fa=find(a),fb=find(b);
			if(c=='D') unit(a,b,fa,fb);
			else if(c=='A') {
				if(fa!=fb) printf("Not sure yet.\n");
				else if(rela[a]==rela[b]) printf("In the same gang.\n");
				else printf("In different gangs.\n");
			}
		}
	}
	return 0;
}
