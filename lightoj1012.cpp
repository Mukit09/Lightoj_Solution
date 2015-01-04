#include<stdio.h>

char ch[25][25];

long count,w,h,flg;

void dfs(long r,long c)
{	
	if(r>=h||r<0||c>=w||c<0||ch[r][c]=='#')
		return ;

	ch[r][c]='#';
	count++;
	
	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+1);
	dfs(r,c-1);
}
	

int main()
{
	long t,k=1,i,j;
	scanf("%ld",&t);
	while(t--)
	{
		count=i=flg=0;
		scanf("%ld%ld",&w,&h);

		for(j=0;j<h;j++)
			scanf("%s",ch[j]);

		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(ch[i][j]=='@')
					dfs(i,j);
			}
		}
		printf("Case %ld: %ld\n",k++,count);
	}
	return 0;
}