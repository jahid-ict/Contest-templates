#define MAXN 100005

vector<int>edge[30005],cost[30005];
long long int maxd;
bool taken[30002];

int dfs(int source)
{
      taken[source]=true;
      int u=source,v;
      int dist1=0,dist2=0,tmp=0;
      for(int j=0;j<edge[u].size();j++)
      {
          v=edge[u][j];
          if(taken[v]==false)
          {
              tmp=cost[u][j]+dfs(v);
              if(tmp>dist1 && dist1<=dist2) dist1=tmp;
              else if(tmp>dist2 && dist1>=dist2) dist2=tmp;
          }
      }
      if(dist1+dist2>maxd) maxd=dist1+dist2;
      if(dist1>dist2) return dist1;
      else return dist2;
}


int main()
{
    int t,w,co=0,m,i,uu,v,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<=n;i++) { edge[i].clear(); cost[i].clear();taken[i]=false;}
        for(i=1;i<n;i++)
        {
            scanf("%d %d %d",&uu,&v,&w);
            edge[uu].push_back(v);
            edge[v].push_back(uu);
            cost[uu].push_back(w);
            cost[v].push_back(w);
        }
        maxd=0;
        dfs(0);
         printf("Case %d: %lld\n",++co,maxd);
    }
    for(i=0;i<=30000;i++) { edge[i].clear(); cost[i].clear();}
    return 0;
}
