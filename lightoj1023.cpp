#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    char ch[50];
    long n,i,k,count,t,j=1;
	scanf("%ld",&t);
	while(t--)
    {
		scanf("%ld%ld",&n,&k);
		for(i=0;i<n;i++)
			ch[i]=i+65;
		ch[i]=0;
		count=0;
        sort(ch,ch+n);

		printf("Case %ld:\n",j++);
        do{
			if(count==k)
				break;
            printf("%s\n",ch);
			count++;
        }while(next_permutation(ch,ch+n)==1);
    }
    return 0;
}