#define MAXN 100005

vector<int> edge[1000],cost[1000];
int d[1005];
queue<int>q;

void BFS(int src)
{
    for(int i=0;i<=1000;i++)  d[i]=inf;
    d[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int ucost=d[u];
        for(int j=0;j<edge[u].size();j++)
        {
            int v=edge[u][j];
            int vcost=ucost+cost[u][j];
            if(d[v]>vcost)
            {
                d[v]=vcost;
                q.push(v);
            }
        }
    }
}

int main()
{
    int e,n,u,v,w;
    scanf("%d %d",&n,&e);
    for(int i=1;i<=e;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(v);
        cost[v].push_back(u);
    }
    BFS(0);
    for(int i=0;i<=1000;i++) {edge[i].clear();cost[i].clear();}

    return 0;
}
