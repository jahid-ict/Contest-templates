i64 extended_euclid(i64 a, i64 b, i64 &X, i64 &Y)
{
    i64 old_r=a,r=b,old_x=1,x=0,old_y=0,y=1,q,tmp;
    //r(i)=r(i-2)-q*(r(i-1))... q=r(i-2)/r(i-1); forthright48 er site theke
    //old_r hbe gcd and old_x,old_y hbe X & Y.
    while(r!=0) // b zero na hle
    {
         q=old_r/r;
        tmp=r;
        r=old_r%r;
        old_r=tmp;

        tmp=x;
        x=old_x-q*x;
        old_x=tmp;

        tmp=y;
        y=old_y-q*y;
        old_y=tmp;
    }
    X=old_x; Y=old_y;
    return old_r;
}

void modinverseExtend(i64 a, i64 m)
{
  i64 X,Y;
  i64 g=extended_euclid(a,m,X,Y);
  if(g<0) g=-g;
  //X/=r;Y/=r;
  pf("%lld %lld %lld\n",X,Y,g);
}
int main()
{
    i64 zz,zzz;
    while(sc("%lld %lld",&zz,&zzz)==2)
    {
      modinverseExtend(zz,zzz);
    }
    return 0;
}
