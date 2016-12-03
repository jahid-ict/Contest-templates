//ei program ta n^m er sum of divisor ber kore dibe in shaa Allah.

#include<cstdio>
#include<cmath>
int a[66000/32];
#define pf printf
int p[66000],c;
long  long M=1000000007;

void prime()
{
    int i,j,sq;
    sq=sqrt(66000);
    for(i=3;i<=sq;i+=2)
    if(((bool)(a[i/32] & (1<<(i%31))))==0) for(j=i*i;j<=66000;j+=(2*i)) a[j/32]=a[j/32]|(1<<(j%31));
    c=0;p[0]=2;
    for(i=3;i<=66000;i+=2) if(((bool)(a[i/32] & (1<<(i%31))))==0) p[++c]=i;
    p[++c]=1000000000;
}

int  find_pow(long long int n,long long int m)
{
    if(m==0) return 1;
    if(m%2==0)
    {
        long long int  ret=find_pow(n,m/2)%M;
        return ((ret%M)*(ret%M))%M;
    }
    else return ((n%M)*(find_pow(n,m-1)%M))%M;
}


long long int   egcd(long long int aa,long long int b,long long int &x,long long int &y)
{
    x=0;y=1;long long int u=1,v=0,m,q,r,nn;
    while (aa != 0){
        q=b/aa; r=b%aa;
        m=x-u*q; nn=y-v*q;
        b=aa; aa=r; x=u; y=v; u=m; v=nn;
         }
        while(x<0){ x+=M;
       }
       while(b<0){ b+=M;
       }
  return b%M;
}

int modIn(long long int aa,long long int m)
{
    long long int x,y,g;
    g=egcd(aa, m,x,y);
    if (g != 1)
        return 0  ;
    else
        return x % m;
}

int main()
{
    prime();
    int tmp,tmp1,k,co=0,res;
    long long   i,n,m1,pp,sq,xx,qs;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        res=1;
        scanf("%lld %lld",&n,&m1);
        pp=n;
        sq=sqrt(pp);
        xx=pp;
        for(i=0;p[i]<=sq && i<c;i++)
        {
            k=0;
            if(xx%p[i]==0)
            {
                while(xx%p[i]==0)
                {
                    xx=xx/p[i];
                    k++;
                }
                qs=(((find_pow(p[i],(k*m1)+1)-1)%M)* (modIn(p[i]-1,M)%M))%M;
                /// eta ekta sutro amr khatay likha ache sundor molot khatay--page-20.
                res=((res%M)* (qs%M))%M;
            }
        }
        if(xx>1)
        {
                qs=(((find_pow(xx,m1+1)-1)%M)  * (modIn(xx-1,M)%M))%M;
                res=((res%M)* (qs%M))%M;
        }
        if(res<0) res+=M;
        printf("Case %d: %d\n",++co,res%M);
    }
    return 0;
}
