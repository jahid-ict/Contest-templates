
int t,q,x,y,x1,y11,x2,y2,c,ind,res,co=0,tree[1005][1005],bl[1005][1005];

void update(int x, int y, int val)
{
    int y1;
    while(x<=1001)
    {
      y1=y;
      while(y1<=1001)
      {
          tree[x][y1]+=val;
          y1+=(y1 & -y1);
      }
      x+=(x & -x);
    }
}

int query(int x ,int y)
{
    int sum=0,y1;
    while(x)
    {
       y1=y;
       while(y1)
       {
           sum+=tree[x][y1];
           y1-=(y1 & -y1);
       }
       x-=(x & -x);
    }
    return sum;
}

int main()
{
    S(t);
    while(t--)
    {
        mem(tree,0);
        pf("Case %d:\n",++co);
       S(q);
       while(q--)
       {
           S(ind);
           if(ind==0)
           {
             S2(x,y);
             x++;y++;
             if(bl[x][y]!=co)
             {
                 bl[x][y]=co;
                 update(x,y,1);
             }
           }
           else
           {
             sc("%d %d %d %d",&x1,&y11,&x2,&y2);
             res=0;
             x1++;y11++;x2++;y2++;
             res=query(x2,y2);
             res-=query(x2,y11-1);
             res-=query(x1-1,y2);
             res+=query(x1-1,y11-1);
             pf("%d\n",res);
           }
       }
    }
    return 0;
}
