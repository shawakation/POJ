#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
stack<char*> forth,backward;
char* curpage=NULL;
int main()
{
	char order[10];
	curpage=new char[72];
	strcpy(curpage,"http://www.acm.org/");
	while(1) {
		scanf("%s",order);
		if(strcmp(order,"QUIT")==0) return 0;
		if(strcmp(order,"VISIT")==0) {
			char* web=new char[72];
			scanf("%s",web);
			backward.push(curpage);
			while(!forth.empty()) forth.pop();
			curpage=web;
		} else if(strcmp(order,"BACK")==0) {
			if(backward.empty()) {
				puts("Ignored");
				continue;
			}
			forth.push(curpage);
			curpage=backward.top();
			backward.pop();
		} else if(strcmp(order,"FORWARD")==0) {
			if(forth.empty()) {
				puts("Ignored");
				continue;
			}
			backward.push(curpage);
			curpage=forth.top();
			forth.pop();
		}
		printf("%s\n",curpage);
	}
	return 0;
}
