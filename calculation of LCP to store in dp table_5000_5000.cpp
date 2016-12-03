#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
char s[5005],p[5005];
char slrss[5005];
int m,n,sa[5005],tmpsa[5005],ra[5005],tmpra[5005],c[5005];
int ow[5005],dp[5005][5005],lcp[5005],phi[5005],plcp[5005],dplcp[5005][5005];

int compute_lcp(int a, int b)
{
        int L=0;
        while(s[sa[a]+L]==s[sa[b]+L]) L++;
        return L;
}
void fast_lcp(int n)
{
   phi[sa[0]]=-1;
   for(int i=1;i<n;i++)
   phi[sa[i]]=sa[i-1];
   for(int i=0,L=0;i<n;i++)
   {
       if(phi[i]==-1) {plcp[i]=0;continue;}
       while(s[i+L]==s[phi[i]+L]) L++;
       plcp[i]=L;
       L=max(L-1,0);
   }
   for(int i=0;i<n;i++) lcp[i]=plcp[sa[i]];
}

int call(int prev, int pres)
{
    //printf("-- %d %d\n",prev,pres);
    if(pres>n-1) {return 1LL;}
    if(dp[prev][pres]!=-1) return dp[prev][pres];
    long long  ret=0;
    if(prev==n)
    {
       ret+=call(pres,pres+1);
    }
    else
    {
            int la=pres-prev;
            int lb=n-pres;
            //   printf("%d %d\n",la,lb);

            if(la<=lb && s[pres]!='0')
            {
           // int l1=compute_lcp(ow[prev],ow[pres]);//etar jnno TLE khacchi
            //  printf("-----------   %d %d %d\n",prev,pres,l);
            int l=dplcp[ow[prev]][ow[pres]];
            //printf("%d %d %d %d\n",prev,pres,l,l1);
            // pf("");

            if(l<la && s[prev+l]<s[pres+l])
            {
                ret+=call(pres,pres+la);
            }
            else if(l<=la && la<lb)
            {
               ret+=call(pres,pres+la+1);
            }
            else if(l==la && la==lb && pres+lb<n)
            {
               ret+=call(pres,pres+lb);
            }
            else if(l>la && la<lb)
            {
               ret+=call(pres,pres+la+1);
            }
            }
            ret=(ret+call(prev,pres+1))%MOD;
    }
    return dp[prev][pres]=ret;
}

void counting_sort(int k)
{
    int i,sum,t,maxi=max(300,n);
    memset(c,0,sizeof c);
    for(i=0;i<n;i++)
    {
        c[i+k<n?ra[i+k]:0]++;
    }
    sum=0;
    for(i=0;i<maxi;i++)
    {
        t=c[i];
        c[i]=sum;
        sum+=t;
    }
    for(i=0;i<n;i++)
    {
     tmpsa[c[sa[i]+k<n?ra[sa[i]+k]:0]++]=sa[i];
    }
    for(i=0;i<n;i++)
    {
        sa[i]=tmpsa[i];
    }
}
void construct_sa(int n)
{
    for(int i=0;i<n;i++) ra[i]=s[i];
    for(int j=0;j<n;j++) sa[j]=j;
    for(int k=1;k<n;k<<=1)
    {
        counting_sort(k);
        counting_sort(0);
        tmpra[sa[0]]=0; int r=0;
        for(int i=1;i<n;i++)
        {
            tmpra[sa[i]]=(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k]) ? r : ++r;
        }
        for(int i=0;i<n;i++) ra[i]=tmpra[i];
        if(ra[sa[n-1]]==n-1) break;
    }
}

int main()
{
    scanf("%d",&n);

    scanf("%s",&s);
    strcat(s,"#");
    n=strlen(s);
    construct_sa(n);
    for(int i=0;i<n;i++)
    {
            ow[sa[i]]=i;
    }
    fast_lcp(n);
    for(int i=0;i<n;i++)
    {
        int mn=200000;
        for(int j=i+1;j<=n;j++)
        {
            mn=min(mn,lcp[j]);
            dplcp[i][j]=dplcp[j][i]=mn;
        }
    }
    n--;
    memset(dp,-1,sizeof dp);
    int res=call(n,0);
    cout<<res;
   // int res=compute_lcp(ow[1],ow[5]);
   // printf("%d\n",res);
    return 0;
}
