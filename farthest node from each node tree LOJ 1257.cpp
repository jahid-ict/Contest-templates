#include<bits/stdc++.h>
using namespace std;
vector<int>edges[30002],cost[30005];
int perm[30002],d[30002],m[30002],i,degree[30002],in[30002],out[30002];
bool visited[30005];
int dfs(int u,int dist)
{
   // printf("%d %d %d\n",u,dist,perm[u]);
  //  if(dist<perm[u] && u!=i) {return perm[u]+dist;}
    visited[u]=true;
    d[u]=m[u]=dist;
    in[u]=max(in[u],dist);
    perm[u]=max(perm[u],dist);
    for(int j=0;j<edges[u].size();j++)
    {
        int v=edges[u][j];
        if(visited[v]==false)
        {
            int ret1=dfs(v,d[u]+cost[u][j]);
            int ret2=ret1-d[u];
            out[u]=max(out[u],ret2);
            perm[u]=max(perm[u],ret2);
            perm[u]=max(perm[u],d[u]);
            m[u]=max(m[u],ret1);
           // printf("%d %d %d %d %d %d %d %d\n",u,v,ret1,ret2,d[u],m[u],perm[u],perm[v]);
        }
    }
    int ret=m[u];
    d[u]=0; m[u]=0; visited[u]=false;
    return ret;
}
int main()
{
    int t,n,u,v,w,co=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
          scanf("%d %d %d",&u,&v,&w);
          degree[u]++; degree[v]++;
          edges[u].push_back(v); edges[v].push_back(u);
          cost[u].push_back(w); cost[v].push_back(w);
        }
        for(i=0;i<n;i++)
        if(degree[i]==1)
        {
          //  printf("%d\n\n",i);
            dfs(i,0);
        }
        printf("Case %d:\n",++co);
        for(i=0;i<n;i++)
         {
             printf("%d\n",perm[i]);edges[i].clear(); cost[i].clear();
             d[i]=in[u]=out[u]=0;perm[i]=0;degree[i]=0;m[i]=0;visited[i]=false;
        }
    }
    return 0;
}

