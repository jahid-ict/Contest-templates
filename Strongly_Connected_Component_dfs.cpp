//directed graph
int n,m,component,u,v;
bool visited[MAX],color[MAX];
stack<int>s;
vector<int>edges[MAX],components[MAX],redges[MAX];

void dfs(int u)
{
    color[u]=true;
    for(int i=0;i<(int)edges[u].size();i++)
        if(color[edges[u][i]]==false)
        dfs(edges[u][i]);
    s.push(u);
}

void dfs2(int u, int component)
{
    visited[u]=true;
    components[component].pb(u);
    for(int i=0;i<(int)redges[u].size();i++)
    {
        if(visited[redges[u][i]]==false)
            dfs2(redges[u][i],component);
    }
}
void find_scc()
{
    repc(i,1,n)
    visited[i]=false,color[i]=false,components[i].clear();
    component=0;
    while(!s.empty()) s.pop();
    for(int i=1;i<=n;i++)
        if(color[i]==false)
        dfs(i);
    while(!s.empty())
    {
        u=s.top();
        s.pop();
        if(visited[u]==false)
        {
            component++;
            dfs2(u,component);
        }
    }
}
int main()
{
    S2(n,m);
    repc(i,1,m)
    {
        S2(u,v);
        edges[u].pb(v);
        redges[v].pb(u);
    }
    find_scc();
    cout<<component,pfn;
    for(int i=1;i<=component;i++)
    {
        for(int j=0;j<components[i].size();j++)
            pf("%d ",components[i][j]);
        pfn;
    }
    repc(i,1,n) components[i].clear(),edges[i].clear(),redges[i].clear();
    return 0;
}
