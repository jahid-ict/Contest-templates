int t,co,p;
double ax,ay,bx,by,cx,cy,dx,dy,mid1,mid2,res,lo,hi,ax1,ay1,bx1,by1,cx1,cy1,dx1,dy2;

double dist(double tm)
{
   ax1=ax+tm*(bx-ax);
   ay1=ay+tm*(by-ay);
   cx1=cx+tm*(dx-cx);
   cy1=cy+tm*(dy-cy);
   ax1-=cx1;
   ay1-=cy1;
   ax1*=ax1;ay1*=ay1;
   return (double)sqrt(ax1+ay1);
}

int main()
{
    S(t);
    while(t--)
    {
        sc("%lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
        res=0;
        p=50;//300 neya standard..ami accepted hobar po time komaichi
        lo=0.0;hi=1.0;
        while(p--)
        {
          mid1=(2*lo+hi)/3;
          mid2=(lo+2*hi)/3;
          if(dist(mid1)<dist(mid2))
          {
              hi=mid2;
          }
          else
          {
              lo=mid1;
          }
        }
        res=dist(lo);
        pf("Case %d: %.10lf\n",++co,res+eps);
    }
    return 0;
}
