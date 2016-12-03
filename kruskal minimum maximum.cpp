/// Minimum & Maximum Spanning Tree ///--> duitar sum weight e rekhe dilam
#include<bits/stdc++.h>
using namespace std;

int par[105],rank[105];

struct data
{
    int u,v,w;
    bool operator<(const data &p)
    const {return w<p.w;}
}edges[12005];

void make_set(int p)
{
    par[p]=p;
    rank[p]=0;
}

int find_parent(int r)
{
    if(par[r]!=r) par[r]=find_parent(par[r]);
    return par[r];
}
int main()
{
    int t,co=0,n,u_,v_,w_,i,m,weight;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&n);

      m=0;
      while(scanf("%d %d %d",&u_,&v_,&w_) && u_ || v_ || w_)
      {
        edges[++m].u=u_;edges[m].v=v_; edges[m].w=w_;
      }


      for(i=0;i<=n;i++)
      make_set(i);
      sort(edges+1,edges+m+1);
      weight=0;
      for(i=1;i<=m;i++)
      {
          u_=find_parent(edges[i].u);
          v_=find_parent(edges[i].v);
          if(u_!=v_)
          {
              weight+=edges[i].w;
              if(rank[u_]>rank[v_]) par[v_]=u_;
              else
              {
                  par[u_]=v_;
                  rank[v_]++;
              }
          }
      }

      ///maximum spanning tree ber korar jnne last theke array hbe.
      for(i=0;i<=n;i++) make_set(i);
      for(i=m;i>=1;i--)
      {
          u_=find_óparent(edges[i].u);
          v_=find_parent(edges[i].v);
          if(u_!=v_)
          {
              weight+=edges[i].w;
              if(rank[u_]>rank[v_]) par[v_]=u_;
              else
              {
                  par[u_]=v_;
                  rank[v_]++;
              }
          }
      }
      printf("Case %d: ",++co);
      if(weight%2==0) printf("%d\n",weight/2);
      else printf("%d/2\n",weight);
    }
    return 0;
}

