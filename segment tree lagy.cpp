struct ST
{
    i64 prop,sum;
}tree[4*100005];

int t,n,q,x,y,co=0,p;
i64 val;

void update(int node, int b, int e, int l, int r, i64 x)
{
    if(l>e || r<b) return;
    if(l<=b && r>=e)
    {
        tree[node].sum+=(x*(e-b+1));
        tree[node].prop+=x;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,l,r,x);
    update(right,mid+1,e,l,r,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
    return;
}

i64 query(int node, int b, int e, int l, int r, i64 carry=0)
{
    if(l>e || r<b) return 0LL;
    if(l<=b && r>=e) return tree[node].sum+(e-b+1)*carry;
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    return query(left,b,mid,l,r,tree[node].prop+carry)+query(right,mid+1,e,l,r,tree[node].prop+carry);
}

int main()
{
    S(t);
    while(t--)
    {
        S2(n,q);
        mem(tree,0);
        while(q--)
        {
            S(p);
            if(p==0)
            {
              S2(x,y);sc("%lld",&val);
              update(1,1,n,x,y,val);
            }
            else
            {
              S2(x,y);
              i64 res=query(1,1,n,x,y,0LL);
              pf("%lld\n",res);
            }
        }
    }
    return 0;
}
