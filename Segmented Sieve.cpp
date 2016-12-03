bool st[10000005],st1[10000005];
vector<i64>prime,segmentprime;

void sieve(i64 b)
{
    b=sqrt(b);
    int sq=sqrt(b);

    for(int i=3;i<=sq;i+=2)
    if(!st[i])
    {
       for(int j=i*i;j<=b;j+=(2*i)) st[j]=true;
    }
    prime.push_back(2);
    for(int i=3;i<=b;i+=2) if(!st[i]) prime.pb(i);
}

void segmented_sieve(i64 a, i64 b)
{
    for(int i=0;i<prime.size();i++)
    {
      i64 t=prime[i];
      i64 st=a/t,ed=b/t;
      ed=ed*t;
      for(i64 j=st*t;j<=ed;j+=(t))
      {
          if(j>=a && j<=b)
          {
              st1[j-a]=true;
          }
      }
    }
    for(int i=0;i<=b-a;i++)
        if(!st1[i] && i+a>1) segmentprime.pb(i+a);
}
int main()
{
    //from a to b where b-a+1<=10000000. a<=b
    /// a,b=1e8~1e14;
    i64 a=99999999000000LL, b=1e14;
    //find prime till sqrt(b);
    sieve(b);
    segmented_sieve(a,b);

    for(int i=0;i<segmentprime.size();i++)
        pf("%lld\n",segmentprime[i]);
    prime.clear();
    segmentprime.clear();
    return 0;
}
