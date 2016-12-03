int ar[10000],tree[30000];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=ar[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    return;
}

int query(int node, int b, int e, int i, int j)
{
 if(b>=i && e<=j) return tree[node];
 if(b>j ||  e<i) return 0;
 int left=2*node;
 int right=2*node+1;
 int mid=(b+e)/2;
 int p1=query(left,b,mid,i,j);
 int p2=query(right,mid+1,e,i,j);
 return p1+p2;
}

void update(int node, int b, int e, int pos, int newV)
{
  if(pos>=b && pos<=e)
  {
      tree[node]=newV;
      return ;
  }
  if(pos<b || pos>e) return;
  int left=2*node;
  int right=2*node+1;
  int mid=(b+e)/2;
  update(left, b,mid,pos,newV);
  update(right,mid+1,e,pos,newV);
  tree[node]=tree[left]+tree[right];
}

int main()
{
    int n,q,x,y,pos,newV;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    printf("Enter the elements:");
    repc(i,1,n) S(ar[i]);
    init(1,1,n);

    pf("Enter the number of query: ");
    scanf("%d",&q);
    while(q--){
    scanf("%d %d",&x,&y);
    int result=query(1,1,n,x,y);
    pf("%d\n",result);}
    printf("Enter the value and position of newValue:");
    scanf("%d %d\n",&pos,&newV);
    update(1,1,n,pos,newV);

    pf("Enter the number of query: ");
    scanf("%d",&q);
    while(q--){
    scanf("%d %d",&x,&y);
    int result=query(1,1,n,x,y);
    pf("%d\n",result);}
    return 0;
}
