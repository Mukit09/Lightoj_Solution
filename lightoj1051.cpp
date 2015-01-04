#include<stdio.h>
#include<string.h>
#define si 51
char ch[si];
int dp[si][4][6],l;

int rec(int i,int vwl,int con)
{
	if(i==l)
	{
		if(vwl==3||con==5)
			return 0;  //bad
		return 1;  //good
	}
	if(dp[i][vwl][con]!=-1)
		return dp[i][vwl][con];

	if(vwl==3||con==5)
		return 0; //bad

	int p,q;
	if(ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U')
		return dp[i][vwl][con]=rec(i+1,vwl+1,0);
	else if(ch[i]=='?')
	{
		if(i)
		{
			if(ch[i-1]=='A'||ch[i-1]=='E'||ch[i-1]=='I'||ch[i-1]=='O'||ch[i-1]=='U')
			{
				ch[i]='A';
				p=rec(i+1,vwl+1,0);
				ch[i]='B';
				q=rec(i+1,0,1);
			}
			else
			{
				ch[i]='A';
				p=rec(i+1,1,0);
				ch[i]='B';
				q=rec(i+1,0,con+1);
			}
			ch[i]='?';
		}
		else
		{
			ch[i]='A';
			p=rec(i+1,vwl+1,con);
			ch[i]='B';
			q=rec(i+1,vwl,con+1);
			ch[i]='?';
		}
		if(!p&&!q)
			return dp[i][vwl][con]=0; //bad
		else if(p==1&&q==1)
			return dp[i][vwl][con]=1; //good
		else
			return dp[i][vwl][con]=2; //mix
	}
	else
		return dp[i][vwl][con]=rec(i+1,0,con+1);
}

int main()
{
	int t,i,x=1,j,k,ans,cnt,fg;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",ch);
		l=strlen(ch);
		fg=1;
		for(i=0;i<l;i++)
		{
			if(ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U')
			{
				cnt=0;
				while((ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U')&&i<l)
				{
					i++;
					cnt++;
				}
				if(cnt>=3)
					fg=0;
			}
			else if(ch[i]>=65&&ch[i]<=90)
			{
				cnt=0;
				while(ch[i]>=65&&ch[i]<=90&&i<l)
				{
					i++;
					cnt++;
					if(ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U')
						break;
				}
				if(cnt>=5)
					fg=0;
			}
		}
		if(!fg)
		{
			printf("Case %d: BAD\n",x++);
			continue;
		}
		for(i=0;i<l;i++)
		{
			for(j=0;j<=3;j++)
			{
				for(k=0;k<=5;k++)
					dp[i][j][k]=-1;
			}
		}
		ans=rec(0,0,0);
		if(ans==2)
			printf("Case %d: MIXED\n",x++);
		else if(ans==1)
			printf("Case %d: GOOD\n",x++);
		else 
			printf("Case %d: BAD\n",x++);

	}
	return 0;
}