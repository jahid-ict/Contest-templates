#include<bits/stdc++.h>
using namespace std;
int par[1000],rank[1000];
void make_set(int p)
{
    par[p]=p;
    rank[p]=0;
}
int find(int r)
{
    if(par[r]!=r) par[r]=find(par[r]);
    return par[r];
}
void union_new(int a,int b)
{
    int u=find(a);
    int v=find(b);
    if(u==v) printf("They are already friends.\n");
    else
    {
        if(rank[u]>rank[v]) par[v]=u;
        else if(rank[u]<rank[v]) par[u]=v;
        else
        {
            par[v]=u;
            rank[u]++;
        }
    }
}

int main()
{
    int i;
    for(i=1;i<=10;i++)
    make_set(i);
    union_new(1,2);
    union_new(1,2);
    return 0;
}
