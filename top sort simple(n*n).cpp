#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<iostream>
using namespace std;

map<string,int>m;
map<int,string>mm;
int nodes_relation[55][55],indegree[100],taken[100],sorted_list[100],c;
bool cycle;
int n;

void topsort()
{
    int i,j,k;
    for( i=1;i<=n;i++)
    {
        for( j=1;j<=n;j++)
        {
            if(taken[j]==0 && indegree[j]==0)
            {
                taken[j]=1;
                sorted_list[i]=j;
                for( k=1;k<=n;k++)
                {
                    if(taken[k]==0 && nodes_relation[j][k]==1)
                    {
                        indegree[k]--;
                    }
                }
                break; /// every time we search for only one;
            }

        }
        if(j>n)
        {
            cycle=true; /// No solution
            break;
        }
    }
}

int main()
{
    int e;
    printf("Enter the number of vertex & edges : ");
    scanf("%d %d",&n,&e);
    printf("Enter the edges:\n");
    for(int i=0;i<e;i++)
    {
       char u[100],v[100];
       scanf("%s %s",&u,&v);
        if(m.find(u)==m.end()){m[u]=++c; mm[c]=u;}
        if(m.find(v)==m.end()){m[v]=++c; mm[c]=v;}
        nodes_relation[m[v]][m[u]]=1;
        indegree[m[u]]++;
    }
    topsort();
    if(cycle==true) printf("Solution Doesn't exist.\n");
    else
    {
        printf("Topological Sorted List -->");
        for(int i=1;i<=n;i++)
        cout<<" "<<mm[sorted_list[i]];
    }
    m.clear();mm.clear();
    return 0;
}
