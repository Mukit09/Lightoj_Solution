//  nicher code ti memory limit dieche,ei karone onnovabe kora legeche... protiti index e 100 tir jonno harmonic 
//mean ber kora hoeche...evabe 10^8/100 size komano hoeche... :)
/* 
#include<stdio.h>
#include<math.h>
#define si 100000010
double a[si];

int main()
{
	long i,n,t,x=1;
	double sm=0,j;
	for(i=1,j=1;i<=si-5;i++,j++)
	{
		sm+=(1/j);
		a[i]=sm;
	}
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		printf("Case %ld: %lf\n",x++,a[n]);
	}
	return 0;
}
*/
//ACCEPTED code
#include<stdio.h>
#include<math.h>
#define si 1000010
double a[si];

int main()
{
	long i,n,t,x=1,m,p;
	double sm=0,j,k,q;
	for(i=1,j=0;i<=si-5;i++,j++)
	{
		for(k=j*100+1;k<=j*100+100;k++)
			sm+=(1/k);
		a[i]=sm;
	}
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		m=n/100;
		p=n%100;
		sm=a[m];
		q=m;
		for(j=1;j<=p;j++)
			sm+=(1/(q*100+j));
		printf("Case %ld: %.10lf\n",x++,sm+1e-12);
	}
	return 0;
}