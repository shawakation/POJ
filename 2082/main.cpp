#include <cstdio>
#include <stack>
using namespace std;
struct rect {
	int width,height;
	rect(int w,int h):width(w),height(h) {}
};
int main()
{
	int n;
	while(1) {
		scanf("%d",&n);
		if(n==-1) return 0;
		int ans=0;
		stack<rect> st;
		for(int i=0; i<n; i++) {
			int w,h;
			scanf("%d%d",&w,&h);
			if(st.empty()||h>=st.top().height) st.push(rect(w,h));
			else {
				int totalw=0;
				while(!st.empty()&&h<st.top().height) {
					totalw+=st.top().width;
					int curarea=totalw*st.top().height;
					ans=max(ans,curarea);
					st.pop();
				}
				st.push(rect(w+totalw,h));
			}
		}
		int totalw=0;
		while(!st.empty()) {
			totalw+=st.top().width;
			int curarea=totalw*st.top().height;
			ans=max(ans,curarea);
			st.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
