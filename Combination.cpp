//Bismillahir Rahmanir Rahim
//Contest Template
//CoU_Campus_Boyz
//Md. Jahidul Hasan(Shakil),ICT,Comilla University
//UVA: Jahid.ict; Codeforces:jahid.ict; LightOJ:8242
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<bitset>
#include<ctime>
//#include<bits/stdc++.h> // for all headers
using namespace std;
#define i64 long long int
#define u64 unsigned long long int
#define sc scanf
#define pf printf
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define rep(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define repc(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define S(z) scanf("%d",&z)
#define SC(z) scanf("%s",&z)
#define CLR(a) a.clear()
#define SZ(a) (int)a.size()
#define pfn printf("\n")
#define mem(a,b) memset(a,b,sizeof a)
#define erase(a) a.erase(a.begin(),a.end())

#define MI map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define SI set<int>
#define SS set<string>
#define SMI multiset<int>
#define VI vector<int>
#define VI2 vector < vector < int > >
#define QU queue<int>
#define PQU priority_queue<int>
#define STK stack<int>
#define pb push_back

#define inf 2000000000
#define pi  acos(-1.0)
#define MAX 1000007
#define MOD 1000003
#define eps 1e-9

template <class T>T sqr(T x) {return x*x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
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
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}

int dx4[]={1,0,-1,0};int dy4[]={0,1,0,-1}; //4 Direction
int dx8[]={1,1,0,-1,-1,-1,0,1};int dy8[]={0,1,1,1,0,-1,-1,-1};//8 direction
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
/*
struct Graph
{
    int u,v,w;
    bool operator<(const Graph& p)
    const {return w<p.w;} // oporerta chotor jnne
}edge[10];

vector<int>edges,cost;

i64 ncr[1005][1005];
void nCr()
{
    repc(i,0,1002) ncr[i][0]=1LL;
    repc(i,1,1002)
    repc(j,1,i)
    ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
}
*/

int fact[1000005];
int main()
{
 //   fin("1067.txt");
  //  fout("1067_1.txt");
  fact[0]=1;
    fact[1]=1;
    repc(i,2,1000000)
    {
        fact[i]=((i64)fact[i-1]*(i64)i)%(i64)MOD;
    }
     int tamp,res,MIofTAMP;
     int t,n,k,co=0;
     S(t);
    while(t--)
    {
      S(n);S(k);
      tamp=((i64)fact[n-k]*(i64)fact[k])%(i64)MOD;
      MIofTAMP=modinverse((i64)tamp,(i64)MOD)%(i64)MOD;
      res=((i64)fact[n]*(i64)MIofTAMP)%(i64)MOD;
      if(res<0) res+=MOD;
      pf("Case %d: %d\n",++co,res);
    }
    return 0;
}
