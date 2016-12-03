int t,n,a[10005],co,mx,cnt[5005],dn[10005],c;
bool tok[10005];
i64 res,tmp[10005],ncr[10005],tt[105];
vector<int>divi[10005];

int main()
{
    /*
    prothome sobgular theke 4 ta kotovabe neya jay.
    then segular jotogula combination er gcd >1 tader ke subtract korte hbe, kheyal rakhte hbe jate
    duibar baad na jay.
    tai ami aage proti number er jnne way gula ber kochi
    then now 2 diye jehetu 6 ke vaag jay tai 6 er jotogula way ache segula 2 er o thakte baddho.
    tai ami segula 2 theke baad dibo. sobgular jnne.
    */
    for(i64 i=4;i<=10000;i++)
    {
        ncr[i]=((i-1)*(i-2)*(i)*(i-3))/24LL;//nC4=((n)*(n-1)*(n-2)*(n-3))/4!;
       // pf("%lld %lld\n",i,ncr[i]);
    }

    for(int i=2;i<=5000;i++)
        for(int j=i+i;j<=5000;j+=i)
        divi[j].pb(i); // j ke kongula dhara vag jay

    S(t);
    while(t--)
    {
        S(n);
        mx=0;
        repc(i,1,n)
        {
           S(a[i]);
           mx=max(mx,a[i]);
        }
        mem(tok,false);
        mem(tmp,0);
        mem(cnt,0);
        for(int i=100;i>=1;i--) // 100*100=10000(maximum number)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]%i==0)
                {
                    cnt[i]++;
                    if(a[j]/i>100) cnt[a[j]/i]++;
                }
            }
        }

        res=ncr[n];
        for(int i=10000;i>=2;i--) {if(cnt[i]>=4) tmp[i]=ncr[cnt[i]];}

        for(int i=10000;i>=2;i--)
        {
            if(tmp[i]>0)
            {
                for(int j=0;j<divi[i].size();j++)
                {
                    tmp[divi[i][j]]-=tmp[i];
                }
            }
            res-=tmp[i];
        }
        pf("Case %d: %lld\n",++co,res);
    }
    repc(i,1,10000) divi[i].clear();
    return 0;
}
