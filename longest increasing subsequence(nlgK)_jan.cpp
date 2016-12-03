
int n,m,a[100005];
int I[1000005],L[1000005];

int LIS(int n)
  {
    int i;
    I[0] =-inf;
    for(i=1;i<=n;i++)
        I[i]=inf;
    int length=0;
    for(i=0;i<n;i++)
        {
        int low,high,mid;
        low=0;
        high=length;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I[mid]<a[i])
                low=mid+1;
            else
                high=mid-1;
        }
        I[low]=a[i];
        if(length<low) // length contains the maximum position
            length=low;
    }
    return length; // return the result

}



int main()
{
   S(n);
   //zero based indexing
   repc(i,0,n-1) S(a[i]);
   int pp=LIS(n);
   pf("%d\n",pp);
 return 0;
}
