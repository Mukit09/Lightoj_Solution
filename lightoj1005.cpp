#include<stdio.h>
long long dp[100][100][100],i,j,t,n,r,l,cs=1;
long long rec(long long row,long long col,long long r)
{
    if(r==0)
		return 1;
    if(col<r || row<r)
		return 0;
    if(dp[row][col][r]>=0)
		return dp[row][col][r];
    if(r==1)
		return row*col;
	long long p1,p2;
	p1=rec(row-1,col-1,r-1);
	p1*=row;
	p2=rec(row,col-1,r);
    return dp[row][col][r]=p1+p2;
}
 
int main()
{
    scanf("%lld",&t);
 
    while(t--)
    {
        scanf("%lld%lld",&n,&r);
 
        for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
			    for(l=0;l<=r;l++)
				    dp[i][j][l]=-1;
        printf("Case %lld: %lld\n",cs++,rec(n,n,r));
    }
    return 0;
}