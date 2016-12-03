double a[102][102],b[102];
int n;


int eliminate(double a[][102], double b[])
{
    int id;
    for(int i=1;i<=n;i++)
    {
        id=i;
        for(int j=i+1;j<=n;j++)
        {
          if(fabs(a[j][i])>fabs(a[id][i]))
          {
            id=j;
          }
        }
       if(a[id][i]==0) return id;
       //jdi ami return na kore continue kori then prothom e ekta varible e=1 declare korte hbe
       //then id er kaj ta e korbe.assign korte hbena
       //loop er last e e++ korte hbe.
       //for(int i=1,e=1;i<=n;i++) emn vabe

        if(id!=i)
        {
            swap(a[i],a[id]);
            swap(b[i],b[id]);
        }
        double tmp=a[i][i];
        //make only x
        for(int j=1;j<=n;j++)
            a[i][j]/=tmp;
        b[i]/=tmp;

          for(int j=1;j<=n;j++)//eta korar fole back substitution phase korte hoy na.
        {
            if(i!=j)
            {
                double factor=a[j][i]/a[i][i];

                for(int k=i;k<=n;k++) // i er aage gula itimoddhe zero
                {
                   a[j][k]-=(factor*a[i][k]);
                }
                b[j]-=(factor*b[i]);
            }
        }
    }
//    for(int i=1;i<=n;i++)
//    {
//        repc(j,1,n)
//         pf("%llf ",a[i][j]);
//          pfn;
//    }
    for(int i=1;i<=n;i++)
        pf("%lf\n",b[i]);
    return -1; //has unique solution
}

void gaussianelemination(double a[][102], double b[])
{

    int res=eliminate(a,b);
    if(res!=-1)
    {
        pf("Singular Matrix.\n");
        if(b[res]>0) pf("Incosistent System.\n");
        else pf("May Have infinite many solution.\n");
    }
    else
    {
        pf("Solution for the System:\n");
        for(int i=1;i<=n;i++)
        {
            pf("%llf\n",b[i]);
        }
    }

}
int main()
{
    S(n); // dimension: ax+by+bz=m(3*3)
    //AX=B .. ax=b
    //O(n^3);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
          sc("%lf",&a[i][j]);
          sc("%lf",&b[i]);
    }
    gaussianelemination(a,b);
    return 0;
}
