#include<bits/stdc++.h>
#define N 10000
int status[10005>>5],p[10000],c,pf[100],k;
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
   p[0]=2;
   for(i=3;i<=N;i+=2)
   if((bool)(check(status[i>>5],i&31))==false) p[++c]=i;
   printf("Numver of prime number: %d\n",c+1);
   puts("\n");
}

void prime_fact(int n)
{
    printf("%d =",n);
    k=-1;
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
            pf[++k]=p[i]; // store unique factor
            sqrtn=int(sqrt((double)n));
        }
    }
    if(n>1)
    {
    printf(" %d",n);
    pf[++k]=n; // remaining n is also a factor
    }
    printf("\n");
}

int euler_phi(int n)
{
    //if(gcd(m,n)==1 , then phi(m*n)=phi(m)*phi(n); phi(36)=phi(9*4)=12::phi(9)*phi(4)=6*2=12
    //phi(prime^K)=prime^K-prime^(K-1)--> phi(n)=n*(1-(1/prime1))*(1-(1/prime2))*...*(1-(1/primeN));
    int i;
    double tamp=1.0;
    for(i=0;i<=k;i++){
    tamp=tamp*(1.0-(1.0/(double)pf[i]));}
    tamp*=(double)n;
    return (int)tamp;
}

int main()
{
    sieve();
    int a,num;
    while(scanf("%d",&a) && a){
    prime_fact(a);
    num=euler_phi(a);//aage input number er prime factorization korte hbe euler pri ber korte hle
    printf("Euler Phi--> %d\n",num);
    }
    return 0;
}

