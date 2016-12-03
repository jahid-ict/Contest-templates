
int n,e;
int mat[105][105],next[105][105],path[100],c;

int floyd(int src, int dest)
{
    repc(k,1,n)
    repc(i,1,n)
    repc(j,1,n)
    if(mat[i][j]>mat[i][k]+mat[k][j])
    {
        mat[i][j]=mat[i][k]+mat[k][j];
        next[i][j]=next[i][k];
    }
    return mat[src][dest];
}

void print_path(int src, int dest)
{
   path[++c]=src;
   /// ami 1st e sob index e destination set kore dilam.
   /// now jdi maje k tomo node e jaowa lage then
   /// ami mat[src][dest] e mat[src][k] set korlam

   while(src!=dest)
   {
       src=next[src][dest];
       path[++c]=src;
   }
}
int main()
{
    int e,x,y,val,src,dest;
    S2(n,e);
    mem(mat,63);
    repc(i,1,n) mat[i][i]=0;
    repc(i,1,e)
    {
        S2(x,y);S(val);
        mat[x][y]=val;
        //mat[y][x]=val;
    }
    pf("Enter the source and destination: ");
    S2(src,dest);
    // setting next to the destination
    repc(i,1,n)
    repc(j,1,n)
    next[i][j]=j;
    int res=floyd(src,dest);
    pf("Shortest length is: %d\n",res);
    c=0;
    print_path(src,dest);
    pf("Path is: ");
    repc(i,1,c) pf("%d   ",path[i]);
    pfn;
    return 0;
}
