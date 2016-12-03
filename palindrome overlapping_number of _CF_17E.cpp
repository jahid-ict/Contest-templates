int Lo[4000005],C,R,Left,N,expand,diff,maxcenter,maxlength,st,en;
i64 shuru[2000005],shesh[2000005];
char s[2000002];

int main()
{
    S(N);
    SC(s);
    int len;
    len=N;
    N=2*N+1;
    Lo[0]=0;Lo[1]=1;
    C=1;
    R=2;
    expand=0;
    maxcenter=1;
    maxlength=1;
    for(int i=2;i<N;i++) //i=currRightPositon
    {
      Left=2*C-i;
      expand=0;
      diff=R-i;
      if(diff>0)
      {
          if(Lo[Left]<diff)
          {
              Lo[i]=Lo[Left];
          }
          else if(Lo[Left]==diff && i==N-1)
          {
              Lo[i]=Lo[Left];
          }
          else if(Lo[Left]==diff && i<N-1)
          {
              Lo[i]=Lo[Left];
              expand=1;
          }
          else if(Lo[Left]>diff)
          {
              Lo[i]=diff;
              expand=1;
          }
      }
      else
      {
        Lo[i]=0;
        expand=1;
      }
      if(expand==1)
      while((i+Lo[i]<N && i-Lo[i]>0) && (((i+Lo[i]+1)%2==0) || (s[(i+Lo[i]+1)/2]==s[(i-Lo[i]-1)/2])))
            Lo[i]++;
      if(Lo[i]>maxlength)
      {
          maxcenter=i;
          maxlength=Lo[i];
      }
      if(i+Lo[i]>R)
      {
          C=i;
          R=i+Lo[i];
      }
    }
    //pf("- %d %d\n",maxcenter,maxlength);
    st=(maxcenter-maxlength)/2;
    en=st+maxlength-1;
//    for(int i=0;i<=N;i++)
//        pf("%d ",Lo[i]);
//    pfn;
//    pfn;
//    for(int i=0;i<=N;i++)
//        pf("%d ",Lo[i]);
//    pfn;
//    pfn;
    int cur,lft,rt;
    len++;
    for(int i=0;i<N;i++)
    {
        if((i%2)==0 && Lo[i]>0)
        {
            cur=i/2;
        lft=(i-Lo[i]+1)/2;
            rt=(i+Lo[i]-1)/2;
            cur++;//segment tree te 1 index er jnne
            lft++;
            rt++;
            shuru[lft]++;
            shuru[cur]--;
            shesh[cur+1]--;
            shesh[rt+2]++;
           // pf("- %d %d %d %d\n",i,lft,cur,rt);
        }
        else if(i & 1)
        {
            cur=i/2;
            lft=(i-Lo[i]+1)/2;
            rt=(i+Lo[i]-1)/2;
            cur++;
            lft++;
            rt++;
             shuru[lft]++;
            shuru[cur+1]--;
            shesh[cur+1]--;
            shesh[rt+2]++;
//pf("%d %d %d %d\n",i,lft,cur,rt);
        }
    }
    for(int i=1;i<=len;i++) shuru[i]+=shuru[i-1],shesh[i]+=shesh[i-1];
    i64 res=0;
    i64 sum=0,tmp;
    i64 ad=0;
    i64 sb=0;

    for(int i=0;i<len-1;i++)
    {
      ad=shuru[i+1];
      sb=shesh[i+1];
      sum+=sb;//ei index er aage jotogula shesh segula baad jotogula
      tmp=(ad*(ad-1LL))/2LL;
      res=(res+tmp+(ad*sum)+MOD)%MOD;
      res=(res+MOD)%MOD;
      sum+=ad;
      if(sum>MOD) sum%=MOD;
    //  cout<<ad<<" "<<sb;pfn;
    }
    pf("%I64d",res);
    return 0;
}
