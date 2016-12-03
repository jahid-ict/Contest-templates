#include<bits/stdc++.h>
#define n 100
int a[10000001>>5],pr[10000000],c;
bool check(int N,int pos)
{
return (bool)(N & (1<<pos));
}
int set(int N,int pos)
{
    return N=(N| (1<<pos));
}
void sieve()
{
    int sqrtn=int (sqrt ((double) n));
    int i,j;
    for(i=3;i<=sqrtn;i++)
    if((bool)check(a[i>>5],i&31)==false)
    {
        for(j=i*i;j<=n;j+=(2*i))
        a[j>>5]=set(a[j>>5],j&31);
    }
    pr[++c]=2;
    for(i=3;i<=n;i+=2)
    if((bool)(check(a[i>>5],i&31))==false)
    pr[++c]=i;
}
int main()
{
    sieve();
    for(int i=1;i<=c;i++) printf("%d\n",pr[i]);
    return 0;
}
