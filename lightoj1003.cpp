#include<stdio.h>
#include<map>
#include<queue>
#include<vector>
#include<string.h>
#include<string>
#define si 20010
using namespace std;
map<string,long>mp;
queue<long>q;
vector<long>ve[si];

long cnt,i,j,n,fg,in[si],k=1,t,l,x;
char ch1[20],ch2[20];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		j=1;
		for(i=1;i<=n;i++)
		{
			scanf("%s%s",ch1,ch2);
			if(mp[ch1]==0)
				mp[ch1]=j++;
	
			if(mp[ch2]==0)
				mp[ch2]=j++;
			ve[mp[ch1]].push_back(mp[ch2]);
			in[mp[ch2]]++;
		}
		n=j-1;
		fg=0;
		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				fg=1;
				q.push(i);
			}
		}
		while(!q.empty())
		{
			x=q.front();
			l=ve[x].size();
			for(i=0;i<l;i++)
			{
				j=ve[x][i];
				in[j]--;
				if(in[j]==0)
					q.push(j);
			}
			q.pop();
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
				cnt++;
			in[i]=0;
			ve[i].clear();
		}
		if(cnt==n)
			printf("Case %ld: Yes\n",k++);
		else
			printf("Case %ld: No\n",k++);
		mp.clear();
	}
	return 0;
}
