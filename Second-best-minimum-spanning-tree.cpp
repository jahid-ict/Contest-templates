///2nd best minimum spanning tree

#include<bits/stdc++.h>
using namespace std;
vector<int>MST_EDGE;
struct G
{
    int u,v,w;
    bool operator<(const G& p)
    const{return w<p.w;}
}edges[100000];
int par[305],rank[305];
void make_set(int r)
{
    par[r]=r;rank[r]=0;
}

int f_p(int r)
{
    if(par[r]!=r) par[r]=f_p(par[r]);
    return par[r];
}

int main()
{
    int t,n,e,i,j,min1st,min2nd,uu,vv,tamp,co=0,ed;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d %d",&n,&e);
       for(i=1;i<=e;i++)
       {
           scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);

       }
       sort(edges+1,edges+e+1);
       min1st=0;
       min2nd=1000000000;
       ///first MST

       for(i=1;i<=n;i++)  make_set(i);
       for(i=1;i<=e;i++)
       {
         uu=f_p(edges[i].u);
         vv=f_p(edges[i].v);
         if(uu!=vv)
         {
             MST_EDGE.push_back(i);
             min1st+=edges[i].w;
             if(rank[uu]>rank[vv]) par[vv]=uu;
             else
             {
                 par[uu]=vv;
                 if(rank[uu]==rank[vv]) rank[vv]++;
             }
         }
       }

       ///2nd MST: for every edge removal,find mst and insert a chord.check if edge==n-1 to become a ST?
       for(i=0;i<(int)MST_EDGE.size();i++)
       {
           tamp=0,ed=0;
           for(j=1;j<=n;j++) make_set(j);
           for(j=1;j<=e;j++)
           {
              uu=f_p(edges[j].u);
              vv=f_p(edges[j].v);
              if(uu!=vv && j!=MST_EDGE[i])
              {
                  ed++;
               tamp+=edges[j].w;
               if(rank[uu]>rank[vv]) par[vv]=uu;
               else
               {
                   par[uu]=vv;
                   if(rank[uu]==rank[vv]) rank[vv]++;
               }
              }
           }
           if(ed==n-1) if(tamp<min2nd) min2nd=tamp;
       }
       printf("%d %d\n",min1st,min2nd);
       MST_EDGE.clear();
    }
    return 0;
}

