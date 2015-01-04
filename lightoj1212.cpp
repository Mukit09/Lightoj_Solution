#include<stdio.h>
#include<string.h>
#include<deque>
using namespace std;

deque<long>dq;
char ch[20];
long i,v,t,n,m,l,k=1;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		printf("Case %ld:\n",k++);
		for(i=1;i<=m;i++)
		{
			scanf("%s",ch);
			if(ch[1]=='u')
			{
				scanf("%ld",&v);
				l=dq.size();
				if(l==n)
				{
					puts("The queue is full");
					continue;
				}
				if(ch[4]=='L')
				{
					dq.push_front(v);
					printf("Pushed in left: %ld\n",v);
				}
				else
				{
					dq.push_back(v);
					printf("Pushed in right: %ld\n",v);
				}
			}
			else
			{
				l=dq.size();
				if(l==0)
				{
					puts("The queue is empty");
					continue;
				}
				if(ch[3]=='L')
				{
					v=dq.front();
					dq.pop_front();
					printf("Popped from left: %ld\n",v);
				}
				else
				{
					v=dq.back();
					dq.pop_back();
					printf("Popped from right: %ld\n",v);
				}
			}
		}
		dq.clear();
	}
	return 0;
}
