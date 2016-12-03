
struct Vector
{
    double x,y;
    Vector(){}
    Vector(double a, double b) {x=a;y=b;}
};

int n;
Vector p[100005],hull[100005];

Vector operator-(Vector a, Vector b)
{
    return Vector(a.x-b.x,a.y-b.y);
}

double dist(Vector a)
{
    return sqrt(a.x*a.x+a.y*a.y);
}
double dotp(Vector a, Vector b)
{
    return (a.x*b.x+a.y*b.y);
}
double crossp(Vector a, Vector b)
{
  return (a.x*b.y-b.x*a.y);
}
int turn(Vector a, Vector b, Vector c)
{
    //cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<" "<<c.x<<" "<<c.y,pfn;
    double pa=crossp(b-a,c-a);
   // cout<<"-----------------------"<<pa<<endl;
    if(fabs(pa)<1e-11) return 0;
    if(pa>0)  return 1;
    return -1;
}
bool cmp(Vector a, Vector b)
{
    int pa=turn(p[1],a,b);
    if(pa==0)
    {
       return dist(p[1]-a)<dist(p[1]-b);
    }
    return pa>0;
}

int convexHull()
{
    int id=1;
    for(int i=2;i<=n;i++)
    {
      if(p[id].y>p[i].y)
            id=i;
      else if(p[id].y==p[i].y && p[id].x>p[i].x)
      {
          id=i;
      }
    }

    swap(p[id],p[1]);

    sort(p+2,p+n+1,cmp);
    for(int i=1;i<=n;i++)
        cout<<p[i].x<<" "<<p[i].y,pfn;

    int tot=0;
    hull[++tot]=p[1];
    hull[++tot]=p[2];
    for(int i=3;i<=n;i++)
    {
        while(tot>1 && turn(hull[tot-1],hull[tot],p[i])<1) tot--;
       hull[++tot]=p[i];
    }
    return tot;
}
int main()
{
    S(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }
    if(n<=2)
    {
        printf("Convex Hull not possible\n");
    }
    int tot=convexHull();
    printf("Total Number of Points: %d\n",tot);
    pf("They are:\n");
    for(int i=1;i<=tot;i++)
        printf("%lf --- %lf\n",hull[i].x,hull[i].y);

    return 0;
}
