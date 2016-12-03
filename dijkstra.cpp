#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
struct data
{
    int city,dist;
bool operator<(const data& p) const { return dist>p.dist;}
};
vector<int> edge[1000],cost[1000];
int d[1005];
priority_queue<data>q;
void dijkstra(int src)
{
    for(int i=0;i<=1000;i++)  d[i]=inf;
    d[src]=0;
    data u,v;
    u.city=src; u.dist=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        if(d[u.city]<u.dist) continue;//Optimization.itemoddhe konota ese jdi update kore fele then r korar drkr nei. CF 450D
        int ucost=d[u.city];
        for(int j=0;j<edge[u.city].size();j++)
        {
            v.city=edge[u.city][j];
            v.dist=ucost+cost[u.city][j];
            if(d[v.city]>v.dist)
            {
                d[v.city]=v.dist;
                q.push(v);
            }
        }
    }
    printf("%d\n",d[5]);
}
int main()
{
    int e,n,u,v,w;
    scanf("%d %d",&n,&e);
    for(int i=1;i<=e;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        edge[u].push_back(v);
        //edge[v].push_back(u);
        cost[u].push_back(w);
       // cost[v].push_back(w);
    }
    dijkstra(1);
    for(int i=0;i<=1000;i++) {edge[i].clear();cost[i].clear();}
    return 0;
}

