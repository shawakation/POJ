#include <cstdio>
#define maxn 32002
using namespace std;
int c[maxn], ans[15002];
int lowbit(int x)
{
	return x & (-x);
}
int getsum(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += c[n];
		n -= lowbit(n);
	}
	return sum;
}
void update(int pos, int num)
{
	while (pos < maxn)
	{
		c[pos] += num;
		pos += lowbit(pos);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ans[getsum(a + 1)]++;
		update(a + 1, 1);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
