#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
queue<int>q;
vector<int>man[102],woman[202];
int mm,v,wmn[202][202],w[202],man_match[105],w_match[205];

void stable_marriage()
{
    while(!q.empty())
    {
     mm=q.front();
      q.pop();
      if((int)man[mm].size()>0)
      {
          v=man[mm].front();
          man[mm].erase(man[mm].begin()+0);//list theke ei maiya kuluj
          if(w[v]==0)
          {
              man_match[mm]=v;
              w_match[v]=mm;
              w[v]=1;
          }
          else if(w[v]==1)
          {
              if(wmn[v][mm]<wmn[v][w_match[v]])
              {
                  q.push(w_match[v]);
                  man_match[mm]=v;
                  w_match[v]=mm;
                  w[v]=1;
              }
              else
              {
                  q.push(mm);
              }
          }
      }
    }
}

int main()
{
    /// O(n^2):: n is the number of male of female
    int u,j,i,n,t,c=0;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&u);
            man[i].push_back(u);
        }
        q.push(i); //proti cheleke queue te  dukai
    }

    for(i=n+1;i<=(2*n);i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&u);
            woman[i].push_back(u);
            wmn[i][u]=j; // chelegular priority      }
            w[i]=0; // meyegula khali
    }

    stable_marriage();
    printf("Case %d:",++c);
    for(i=1;i<=n;i++)
    {
    printf(" (%d %d)",i,man_match[i]);
    man[i].clear();woman[n+i].clear();
    }
    printf("\n");
    }
    return 0;
}

