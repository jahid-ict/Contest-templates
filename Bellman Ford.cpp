//Bismillahir Rahmanir Rahim
//Md. Jahidul Hasan Shakil
//Dept. of ICT, Comilla University

#include<bits/stdc++.h>
using namespace std;

#define i64 long long int
#define u64 unsigned long long int
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define repc(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define repr(i,a,b) for(__typeof(b) i=(a); i>=(b); i--)
#define clr(a) a.clear()
#define sz(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof a)
#define ERASE(a) a.erase(a.begin(),a.end())

#define sc scanf
#define S(z) scanf("%d",&z)
#define SL(z) scanf("%I64d",&z)
#define SC(z) scanf("%s",&z)

#define S2(xx,zz) scanf("%d %d",&xx,&zz)
#define SL2(xx,zz) scanf("%I64d %I64d",&xx,&zz)

#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define SL3(x,y,z) scanf("%I64d %I64d %I64d",&x,&y,&z)


#define pf printf
#define pfn printf("\n")
#define pfs printf(" ")

#define PF(z) printf("%d",z)
#define PFL(z) printf("%I64d",z)
#define PFS(z) printf("%s",z)

#define PF2(x,y) printf("%d %d",x,y)
#define PFL2(x,y) printf("%I64d %I64d",x,y)

#define PF3(x,y,z) printf("%d %d %d",x,y,z)
#define PFL3(x,y,z) printf("%I64d %I64d %I64d",x,y,z)


#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define inf 2000000007
#define pi  acos(-1.0)
#define MAX 200007
#define MOD 1000000007LL
#define eps 1e-13

template <class T>T sqr(T x) {return x*x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0) return 1;
    if(e%2==0){i64 t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((i64)bigmod(p,e-1,M)*(i64)p)%M;
}
template <class T> inline T bigexp(T p,T e)
{
    if(e==0)return 1;
    if(e%2==0){i64 t=bigexp(p,e/2);return (T)((t*t));}
    return (T)((i64)bigexp(p,e-1)*(i64)p);
}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int dx4[]={1,0,-1,0};int dy4[]={0,1,0,-1}; //4 Direction
int dx8[]={1,1,0,-1,-1,-1,0,1};int dy8[]={0,1,1,1,0,-1,-1,-1};//8 direction
int nx8[]={1,1,-1,-1,2,2,-2,-2};int ny8[]={2,-2,2,-2,1,-1,1,-1};//8 direction-knight
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
/*
struct Graph
{
    int u,v,w;
    bool operator<(const Graph& p)
    const {return w<p.w;} // oporerta chotor jnne
}edge[10];
struct compare
{
    bool operator()(const int&l,const int&r)
    {
        return l>r;
    }
};
priority_queue<int,vector<int>,compare>pq;

i64 ncr[1005][1005];
void nCr()
{
    repc(i,0,1002) ncr[i][0]=1LL;
    repc(i,1,1002)
    repc(j,1,i)
    ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
}
*/
///-------------------Algos-------------------///
/*

*/

/******************* Code Starts here *******************/
#define MAXN 100005

struct edge{
    int u,v,w;
};
edge edges[1024];

vector<int>ans;
int n,e,d[1024],src,path[1000];
int bellman_ford(int src,int dest)
{
    for(int j=1;j<=n;j++)
    d[j]=inf;
    d[src]=0;//source er take zero kore dite hbe.
    for(int j=1;j<n;j++)//node-1 times
    {
        for(int i=1;i<=e;i++)
        {
            if(d[edges[i].u]+edges[i].w<d[edges[i].v])
            {
            d[edges[i].v]=d[edges[i].u]+edges[i].w;
            path[edges[i].v]=edges[i].u;
            }
        }
    }
    //for(int i=1;i<=n;i++) printf("%d %d\n",i,d[i]);
    for(int i=1;i<=e;i++)
    if(d[edges[i].u]+edges[i].w<d[edges[i].v])
    printf("Graph Contain a negative weight cycle.....\n");

    return d[dest];
}
int main()
{
    int src,dest,res;
    scanf("%d %d",&n,&e);//node-edges
    for(int i=1;i<=e;i++)
    {
        int uu,vv,ww;
        scanf("%d %d %d",&uu,&vv,&ww);
        edges[i].u=uu; edges[i].v=vv; edges[i].w=ww;
    }
    for(int i=1;i<=n;i++) path[i]=inf;//path
    //for(int i=1;i<=n;i++)
    //printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].w);
    //path printing.
    //printf("Enter source and destination: ");
    scanf("%d %d",&src,&dest);
    res=bellman_ford(src,dest);
    printf("Shortest path is %d\n",res);
    //path printing
    while(dest!=inf)
    {
      ans.push_back(dest);
       dest=path[dest];
    }
    for(int i=1;i<=n;i++)
    printf("%d %d\n",i,path[i]);
    for(int i=ans.size()-1;i>=0;i--)
    {
      printf("%d  ",ans[i]);
    }

    printf("\n");
    return 0;
}
