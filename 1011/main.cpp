#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 66
using namespace std;
int n,aim,num,len[maxn];
bool isuse[maxn]= {0};
bool search(int stick,int lens,int pos)
{
	bool sig=(lens==0)?1:0;
	if (stick==num) return 1;
	for (int i=pos+1; i<n; i++) {
		if (isuse[i]) continue;
		if (lens+len[i]==aim) {
			isuse[i]=1;
			if (search(stick+1,0,-1)) return 1;
			isuse[i]=0;
			return 0;
		} else if (lens+len[i]<aim) {
			isuse[i]=1;
			if (search(stick,lens+len[i],i)) return 1;
			isuse[i]=0;
			if (sig) return 0;
			while (len[i]==len[i+1]) i++;
		}
	}
	return 0;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	while (1) {
		scanf("%d",&n);
		if (n==0) break;
		int sum=0;
		for (int i=0; i<n; i++) {
			scanf("%d",&len[i]);
			sum+=len[i];
		}
		sort(len,len+n,cmp);
		for (aim=len[0]; aim<=sum; aim++) {
			if (sum%aim==0) {
				num=sum/aim;
				memset(isuse,0,sizeof(isuse));
				if (search(1,0,-1)) {
					printf("%d\n",aim);
					break;
				}
			}
		}
	}
	return 0;
}
