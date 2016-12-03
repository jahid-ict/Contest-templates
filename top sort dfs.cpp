#include<bits/stdc++.h>
using namespace std;

vector<int>edges[1000];
map<string,int>m;
map<int,string>mm;

int c=0,visited[1000],taken[1000],node=0,listt[1000];
bool cycle;

void dfs(int p)
{
    if(taken[p]==0)
    {
        taken[p]=1;
        for(int j=0;j<edges[p].size();j++)
        dfs(edges[p][j]);
        listt[++node]=p;
    }
}

void cycle_check(int p)
{
   if(visited[p]==2 || cycle) return;
   if(visited[p]==1) {cycle=true; return;}
   visited[p]=1;
   for(int j=0;j<edges[p].size();j++)
   {
       cycle_check(edges[p][j]);
   }
   visited[p]=2;
}

int main()
{
    string u,v;
    int n,e;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        if(m.find(u)==m.end()) {m[u]=++c; mm[c]=u;}
        if(m.find(v)==m.end()) {m[v]=++c; mm[c]=v;}
        edges[m[u]].push_back(m[v]);
    }
    /// cycle checking
    for(int i=1;i<=n;i++)
    {
        cycle=false;
        cycle_check(i);
        if(cycle==true) {printf("There's a cycle in this graph. :( "); break;}
    }

///topsort generating start
    for(int i=1;i<=n;i++)
    {
      dfs(i);
    }
    for(int i=1;i<=node;i++)
    cout<<" "<<mm[listt[i]];
    m.clear();mm.clear(); for(int i=0;i<=1000;i++) edges[i].clear();
    return 0;
}
