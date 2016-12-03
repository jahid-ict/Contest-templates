int tree[100005],n;
void make_tree(int n)
{
    for(int i=1;i<=n;i++)
    {
        int p=i,idx=i;
        while(idx<=n)
        {
            tree[idx]+=i;
            idx+=(idx & -idx);
        }
    }
}

int query(int n)
{
    int res=0,idx=n;
    while(idx>0)
    {
        res+=tree[idx];
        idx=idx-(idx & -idx);
    }
    return res;
}
void update_tree(int upd, int idx)
{
    while(idx<=n)
    {
        tree[idx]+=upd;
        idx+=(idx & -idx);
    }
}


int minimum_idx(int num)
{
    int low=1,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        int q=query(mid);
        if(q==num) return mid;
        if(q<num) low=mid+1;
        else high=mid-1;
    }
    if(low>n) return 0;
    else return low;

}
int main()
{
    //fin("C5_8.in");
    //fout("C5_8.txt");
    int t,low,high,index,update,num;
    printf("Enter the max number:");
    scanf("%d",&n);
    make_tree(n);  //making BIT
    printf("How many query:");
    scanf("%d",&t);
    while(t--)
    {
        printf("Enter  the ranges: ");
        scanf("%d %d",&low,&high);
        printf("%d\n",query(high)-query(low-1));
    }
    /// updating part;
    printf("Enter the number to update and index:");
    scanf("%d %d",&update,&index);
    update_tree(update,index);
    printf("How many query:");
    scanf("%d",&t);
    while(t--)
    {
        printf("Enter  the ranges: ");
        scanf("%d %d",&low,&high);
        printf("%d\n",query(high)-query(low-1));
    }
    /// Search part:
    scanf("%d",&t);
    while(t--)
    {
    printf("Enter the summation to get its minimum index:");
    scanf("%d",&num);
    int idx=0;
    if(num>0) idx=minimum_idx(num);
    if(idx==0) printf("Not found.\n");
    else printf("At %d\n",idx);
    }
    return 0;
}
