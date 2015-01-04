#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<stack>
using namespace std;

stack<string>sf,sb,sc;

int main()
{
	long i,j,k=1,t,l;
	char st[100];
	scanf("%ld",&t);
	while(t--)
	{
		printf("Case %ld:\n",k++);
		sc.push("http://www.lightoj.com/");
		while(scanf("%s",st))
		{
			if(strcmp(st,"QUIT")==0)
				break;
			if(strcmp(st,"BACK")==0)
			{
				if(sb.size()==0)
				{
					printf("Ignored\n");
					continue;
				}
				sf.push(sc.top());
				sc.pop();
				sc.push(sb.top());
				sb.pop();
				cout<<sc.top()<<endl;
			}
			else if(strcmp(st,"FORWARD")==0)
			{
				if(sf.size()==0)
				{
					printf("Ignored\n");
					continue;
				}
				sb.push(sc.top());
				sc.pop();
				sc.push(sf.top());
				sf.pop();
				cout<<sc.top()<<endl;
			}
			else if(strcmp(st,"VISIT")==0)
			{
				scanf("%s",st);
				sb.push(sc.top());
				sc.pop();
				sc.push(st);
				while(!sf.empty())
					sf.pop();
				cout<<sc.top()<<endl;
			}
		}
		while(!sc.empty())
			sc.pop();
		while(!sb.empty())
			sb.pop();
		while(!sf.empty())
			sf.pop();
	}
	return 0;
}