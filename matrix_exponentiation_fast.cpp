struct matrix
{
   int v[3][3];
   int row,col;
};
int t,co,M=10007,n,res;

matrix multiply(matrix &a, matrix &b)
{
    matrix ret;
    //a.col==b.row hte hbe.
    ret.row=a.row,ret.col=b.col;
    for(int i=0;i<ret.row;i++)
    {
        for(int j=0;j<ret.col;j++)
        {
            int sum=0;
            for(int k=0;k<a.col;k++)
            {
                sum=(sum%M+(a.v[i][k]%M*b.v[k][j]%M)%M)%M;
            }
            ret.v[i][j]=sum%M;
        }
    }
    return ret;
}


matrix pow(matrix mat, int k)
{
  if(k==1) return mat;
  matrix ret=pow(mat,k/2);
  ret=multiply(ret,ret);
  if(k%2==0) return ret;
  return multiply(mat,ret);
}
int main()
{
    matrix mat;
    S(t);
    while(t--)
    {
      S(n);
      mat.row=3,mat.col=3;
      mat.v[0][0]=2;mat.v[0][1]=0;mat.v[0][2]=1;
      mat.v[1][0]=1;mat.v[1][1]=0;mat.v[1][2]=0;
      mat.v[2][0]=0;mat.v[2][1]=1;mat.v[2][2]=0;
      if(n==1) res=1;
      else if(n==2) res=2;
      else if(n==3) res=5;
      else
      {
          matrix ma=pow(mat,n-3); // jotota deya thakbe n-toto
          res=0;
          res=((ma.v[0][0]*5)%M+(ma.v[0][1]*2)%M+(ma.v[0][2]*1)%M)%M;
          res%=M;
      }
      pf("Case %d: %d\n",++co,res);
    }
    return 0;
}
