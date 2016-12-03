#include<bits/stdc++.h>


#define N 10000
int status[10005>>5],p[10000],c;
bool check(int n,int pos)
{
    return ((bool)(n & 1<<pos));
}
int set(int n,int pos)
{
    return n=(n | 1<<pos);
}

void sieve()
{
   int i,j,sqrtn;
   sqrtn=int(sqrt((double)N));
   for(i=3;i<=sqrtn;i+=2)
   if((bool)(check(status[i>>5],i&31))==false)
   {
       for(j=i*i;j<=N;j+=(2*i))
       status[j>>5]=set(status[j>>5],j&31);
   }
   p[++c]=2;
   for(i=3;i<=N;i+=2)
   if((bool)(check(status[i>>5],i&31))==false) p[++c]=i;
   printf("%d\n",c+1);
}

void prime_fact(int n)
{
    printf("%d =",n);
    int sqrtn=int(sqrt((double)n)),i,j;
    for(i=0;p[i]<=sqrtn && i<=c;i++)
    {
        if(n%p[i]==0)
        {
            while(n%p[i]==0)
            {
                n=n/p[i];
                printf(" %d",p[i]);
            }

            sqrtn=int(sqrt((double)n));
        }
    }
    if(n>1)
    printf(" %d",n);
    printf("\n");
}

int main()
{
    sieve();
    int a;
    while(scanf("%d",&a) && a)
    prime_fact(a);
    return 0;
}
