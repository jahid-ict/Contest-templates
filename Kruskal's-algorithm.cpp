#include<bits/stdc++.h>
using namespace std;
int par[1000],rank[1000];

struct data
{
    int u,v,w;
    bool operator<(const data& p)
    const {return w<p.w;}
}edges[1000];

void make_set(int p)
{
    par[p]=p;
    rank[p]=0;
}
int find_parent(int r)
{
    if(r!=par[r]) par[r]=find_parent(par[r]);
    return par[r];
}
int main()
{
    int n,m,i,weight,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    }
    for(i=1;i<=n;i++) make_set(i);
    weight=0;
    sort(edges+1,edges+m+1);
    for(i=1;i<=m;i++)
    {
      a=find_parent(edges[i].u);
      b=find_parent(edges[i].v);
      if(a!=b)
      {
          weight+=edges[i].w;
          if(rank[a]>rank[b])
          par[b]=a;
          else {
          par[a]=b;
          if(rank[a]==rank[b]) rank[b]++;   }
      }
    }
    printf("%d\n",weight);
    for(i=1;i<=m;i++)
    printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].w);
    return 0;
}
