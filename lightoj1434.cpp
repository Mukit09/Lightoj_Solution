#include<stdio.h>
#include<string.h>

#define si 50

char ch[si][si],st[si];
long n,m,fg,l,res[si],row,col;

void dfs(long r,long c,long i)
{
	if(i==0)
	{
		row=r+1;
		col=c+1;
		fg=1;
		return ;
	}

	if(r<0||c<0||r==n||c==m||fg)
		return ;
	if(ch[r][c]!=st[i])
		return ;
	if(st[i-1]==ch[r][c+1]&&!fg&&(c+1)<m)
	{
		dfs(r,c+1,i-1);
		res[i]=1;
	}
	if(st[i-1]==ch[r][c-1]&&!fg&&(c-1)>=0)
	{
		dfs(r,c-1,i-1);
		res[i]=2;
	}
	if(st[i-1]==ch[r+1][c]&&!fg&&(r+1)<n)
	{
		dfs(r+1,c,i-1);
		res[i]=3;
	}
	if(st[i-1]==ch[r-1][c]&&!fg&&(r-1)>=0)
	{
		dfs(r-1,c,i-1);
		res[i]=4;
	}
	if(st[i-1]==ch[r+1][c+1]&&!fg&&(r+1)<n&&(c+1)<m)
	{
		dfs(r+1,c+1,i-1);
		res[i]=5;
	}
	if(st[i-1]==ch[r+1][c-1]&&!fg&&(r+1)<n&&(c-1)>=0)
	{
		dfs(r+1,c-1,i-1);
		res[i]=6;
	}
	if(st[i-1]==ch[r-1][c+1]&&!fg&&(r-1)>=0&&(c+1)<m)
	{
		dfs(r-1,c+1,i-1);
		res[i]=7;
	}
	if(st[i-1]==ch[r-1][c-1]&&!fg&&(r-1)>=0&&(c-1)>=0)
	{
		dfs(r-1,c-1,i-1);
		res[i]=8;
	}
	if(st[i-1]==ch[r][c]&&!fg)
	{
		dfs(r,c,i-1);
		res[i]=9;
	}
}

int main()
{
	long t,i,j,x=1,q;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s",ch[i]);
		scanf("%ld",&q);
		printf("Case %ld:\n",x++);
		while(q--)
		{
			scanf("%s",st);
			fg=0;
			l=strlen(st);
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(st[l-1]==ch[i][j])
					{
						dfs(i,j,l-1);
						if(fg)
							break;
					}
				}
				if(fg)
					break;
			}
			if(!fg)
				printf("%s not found\n",st);
			else
			{
				printf("%s found: (%ld,%ld)",st,row,col);
				for(i=1;i<l;i++)
				{
					if(res[i]==1)
						printf(", L");
					else if(res[i]==2)
						printf(", R");
					else if(res[i]==3)
						printf(", U");
					else if(res[i]==4)
						printf(", D");
					else if(res[i]==5)
						printf(", UL");
					else if(res[i]==6)
						printf(", UR");
					else if(res[i]==7)
						printf(", DL");
					else if(res[i]==8)
						printf(", DR");
					else if(res[i]==9)
						printf(", *");
				}
				printf("\n");
			}
		}
	}
	return 0;
}