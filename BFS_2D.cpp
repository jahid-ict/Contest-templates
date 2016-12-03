#define MAXN 100005

int w,h,took[25][25];

char s[25][25];
struct data
{
    int x1, y1;
};
bool isvalid(int a, int b)
{
    return a>=0 && a<=h && b>=0 && b<=w;
}
int bfs(int x, int y)
{
  queue<data>q;
  data u,v;
  u.x1=x;
  u.y1=y;
  q.push(u);
  int res=0;
  while(!q.empty())
  {
    u=q.front();
    q.pop();
    x=u.x1;y=u.y1;
    for(int i=0;i<4;i++)
    {
        if((bool)isvalid(x+dx4[i],y+dy4[i])==true && took[x+dx4[i]][y+dy4[i]]==0 && s[x+dx4[i]][y+dy4[i]]=='.')
        {
          took[x+dx4[i]][y+dy4[i]]=1;
          res++;
          v.x1=x+dx4[i];
          v.y1=y+dy4[i];
          q.push(v);
        }
    }
  }
  return res;
}
int main()
{
    int t,co=0,src,dest;
    S(t);
    while(t--)
    {
      S2(w,h);
      getchar();
      src=-1;
      repc(i,1,h)
      {
          gets(s[i]);
          if(src<0)
          repc(j,0,w-1)
          if(s[i][j]=='@')
          {
              src=i;dest=j;
              break;
          }
      }
      mem(took,0);
      int res=bfs(src,dest);
      pf("Case %d: %d\n",++co,res+1);
    }


    return 0;
}
