#include<stdio.h>

long a, b, c, d, e, f,dp[10010];
long  fn(long  n )
 {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
	if(dp[n]!=-1)
		return dp[n];
	dp[n]=(fn(n-1)% 10000007 + fn(n-2)% 10000007 + fn(n-3)% 10000007 + fn(n-4)% 10000007 + fn(n-5)% 10000007 + fn(n-6)% 10000007)% 10000007 ;
    return dp[n]; 
}
int main() 
{
    long  n, k = 1, t,i;
    scanf("%lld", &t);
    while( t-- ) 
	{
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
		for(i=0;i<=n;i++)
			dp[i]=-1;
        printf("Case %lld: %lld\n", k++, fn(n) % 10000007);
    }
    return 0;
}
