#include<stdio.h>
#include<string.h>
#define si 510

char ch[si][si];
char chk[si][si];
long n,m,cnt,res[si][si];

void dfs(long r,long c)
{
	if(r<0||c<0||r>=m||c>=n||ch[r][c]=='#')
		return ;
	
	if(ch[r][c]=='C')
		cnt++;
	ch[r][c]='#';
	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+1);
	dfs(r,c-1);
}

void dfs1(long r,long c)
{
	if(r<0||c<0||r>=m||c>=n||chk[r][c]=='#')
		return ;
	chk[r][c]='#';
	res[r+1][c+1]=cnt;
	dfs1(r+1,c);
	dfs1(r-1,c);
	dfs1(r,c+1);
	dfs1(r,c-1);
}	

int main()
{
	long i,j,q,t,k=1,x,a,b;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld%ld",&m,&n,&q);
		for(i=0;i<m;i++)
		{
			scanf("%s",ch[i]);
			strcpy(chk[i],ch[i]);
		}

		printf("Case %ld:\n",k++);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(ch[i][j]!='#')
				{
					cnt=0;
					dfs(i,j);
					dfs1(i,j);
				}
			}
		}
		for(x=1;x<=q;x++)
		{
			scanf("%ld%ld",&a,&b);
			printf("%ld\n",res[a][b]);
		}
	}
	return 0;
}