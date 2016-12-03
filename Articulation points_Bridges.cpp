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

vector<int> edges[MAXN];
int dfscounter,dfsroot,rootchildren,parent[MAXN],dfs_num[MAXN],dfs_low[MAXN];
bool articulation_vertex[MAXN];

void articulation_point(int u)
{
    dfs_num[u]=dfs_low[u]=dfscounter++;
    for(int j=0;j<edges[u].size();j++)
    {
        int v=edges[u][j];
        if(dfs_num[v]==-1)
        {
            if(dfsroot==u)
            rootchildren++;
            parent[v]=u;
            articulation_point(v);
            if(dfs_low[v]>=dfs_num[u]) articulation_vertex[u]=true;
            if(dfs_low[v]>dfs_num[u])
            {
                printf("Bridges: %d --> %d\n",u,v);
            }
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(v!=parent[u])
        dfs_low[u]=min(dfs_low[u],dfs_num[v]);
    }
}

int main()
{
    int n,m,i,u,v;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        dfs_num[i]=-1; articulation_vertex[i]=false;
    }
    dfscounter=0;
    printf("Bridges:\n");
    for(i=1;i<=n;i++)
    if(dfs_num[i]==-1)
    {
        rootchildren=0; dfsroot=i;
        articulation_point(i);
        articulation_vertex[i]=(rootchildren>1);//special case
    }

    printf("Articulation Points: ");
    for(i=1;i<=n;i++)  if(articulation_vertex[i]==true) printf(" %d",i);
    printf("\n");
    for(i=1;i<=n;i++) edges[i].clear();
    return 0;
}
