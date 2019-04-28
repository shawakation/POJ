/*
注意点一：线段树找 1-n 位置上的和等于 k 的 n 的写法
*/
#include <cstdio>
#define maxn 8001
using namespace std;
int arr[maxn],ans[maxn];
struct node {
	int left,right,val;
	node():left(0),right(0),val(0) {}
	node(int l,int r,int v):left(l),right(r),val(v) {}
};
node tree[4*maxn];
void build(int v,int l,int r)
{
	tree[v].left=l;
	tree[v].right=r;
	if(l==r) {
		tree[v].val=1;
		return;
	}
	int mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	tree[v].val=tree[v*2].val+tree[v*2+1].val;
}
//注意点一
int query(int v,int k)
{
	tree[v].val--;
	if(tree[v].left==tree[v].right) return tree[v].left;
	else if(k<=tree[v*2].val) return query(v*2,k);
	else return query(v*2+1,k-tree[v*2].val);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2; i<=n; i++) scanf("%d",&arr[i]);
	arr[1]=0;
	build(1,1,n);
	for(int i=n; i>=1; i--) ans[i]=query(1,arr[i]+1);
	for(int i=1; i<=n; i++) printf("%d\n",ans[i]);
	return 0;
}
