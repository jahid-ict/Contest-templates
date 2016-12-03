#include<bits/stdc++.h>

#define MX 5000010
int a[MX/32],i,j,a1,b,t,co=0;
double res1[MX];

void sieve()
{
    int sq=sqrt((double)MX);
     for(i=3;i<=sq;i+=2)
     {
         if((bool)(a[i/32] & (1<<i%32))==0)
         {
             for(j=i*i;j<=MX;j+= 2*i)
             {
                 a[j/32]=a[j/32] | (1<<j%32);
             }
         }
     }

     res1[1]=0;
     for(i=2;i<=MX;i++) res1[i]=(double)i;//finding number of relative prime
     for(i=3;i<=MX;i+=2)
     if((bool)(a[i/32] & (1<<i%32))==0)
     {
         for(j=i;j<=MX;j+=i)
         res1[j]=res1[j]*((double)(1.0-(1.0/(double)i)));
     }
     for(i=2;i<=MX;i+=2) res1[i]=res1[i]*((double)(1.0-(1.0/(double)2)));
     for(i=2;i<=MX;i++)
     {
         res1[i]=(res1[i]*res1[i])+res1[i-1];
     }
}

int main()
{
    //res1[] contain number of relative prime
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a1,&b);
       printf("Case %d: %llu\n",++co,(long long)res1[b]-(long long)res1[a1-1]);
    }
    return 0;
}
