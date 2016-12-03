///0 keu kintu 3 dara vaag jay jeta d te rakhchi build korar somoy, taile protitai prothom jay.
struct T
{
    int a,b,c,d,prop;//a=1,b=2,c=3
}tree[300005];

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].d=1;//protita index ke counting
        return ;
    }
    int left=2*node,right=2*node+1,mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].d=tree[left].d+tree[right].d;
}

void update(int node, int b, int e, int i, int j)
{
    if(b>j || e<i)
    {
        return;
    }
    if(b>=i && e<=j)
    {
        int tamp=tree[node].c+tree[node].d;// three+zero
        tree[node].c=tree[node].b;
        tree[node].b=tree[node].a;
        tree[node].a=tamp;
        tree[node].d=0;//zero gula removed
        tree[node].prop++;
        return;
    }
    int left=2*node,right=2*node+1,mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    tree[node].a=tree[left].a+tree[right].a;
    tree[node].b=tree[left].b+tree[right].b;
    tree[node].c=tree[left].c+tree[right].c;
    tree[node].d=tree[left].d+tree[right].d;
    int rem=tree[node].prop%3;
       if(rem==1)
       {
        int tamp=tree[node].c+tree[node].d; tree[node].c=tree[node].b;
            tree[node].b=tree[node].a; tree[node].a=tamp;
       tree[node].d=0;
       }
       else if(rem==2)
       {
        int tamp=tree[node].c+tree[node].d; tree[node].c=tree[node].b;
            tree[node].b=tree[node].a; tree[node].a=tamp;
            tamp=tree[node].c;tree[node].c=tree[node].b;
            tree[node].b=tree[node].a; tree[node].a=tamp;
            tree[node].d=0;
       }
    return ;
}

int query(int node, int b, int e, int i, int j, int carry)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j)
    {
       int rem=carry%3;
       int aa=tree[node].a,bb=tree[node].b,cc=tree[node].c+tree[node].d;
       if(rem==1)
       {
        int tamp=cc; cc=bb;
            bb=aa; aa=tamp;
       }
       else if(rem==2)
       {
        int tamp=cc; cc=bb;
            bb=aa; aa=tamp;
            tamp=cc; cc=bb;
            bb=aa; aa=tamp;
       }
       return cc;
    }
    int left=2*node,right=2*node+1,mid=(b+e)/2;
    return query(left,b,mid,i,j,carry+tree[node].prop)+query(right,mid+1,e,i,j,tree[node].prop+carry);
}

int main()
{
    int n,q,t,id,x,y,res,co=0;
    S(t);
    while(t--)
    {
        mem(tree,0);
        S2(n,q);
        build(1,1,n);
        pf("Case %d:\n",++co);
        while(q--)
        {
            S(id);
            if(id==0)
            {
               S2(x,y);
               update(1,1,n,x+1,y+1);
            }
            else
            {
               S2(x,y);
               x++;y++;
               res=query(1,1,n,x,y,0);
               pf("%d\n",res);
            }
        }
    }
    return 0;
}
