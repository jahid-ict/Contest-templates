int t,n,co;
u64 a[100005],res;

bool cmp(u64 a, u64 b)
{
    return a>b;
}

bool valid(u64 a, int pos)
{
    return (a & (1LL<<pos));
}

int main()
{
   /// https://myprogrammingdesk.wordpress.com/2015/01/31/gaussian-elimination-technique/
   // fout("1272.txt");
   // S(t);
   // while(t--)
    {
        S(n);
        repc(i,1,n) sc("%llu",&a[i]);
        sort(a+1,a+n+1,cmp);

        int pos=63;

        for(int i=63;i>=0;i--)
        if(valid(a[1],i))
            {
              pos=i; break;
            }

        if(n<(pos+1)) {for(int i=n+1;i<=(pos+1);i++) a[i]=0; n=pos+1;}
       //repc(i,1,n) pf("%llu\n",a[i]);
       //pfn;

        res=0;
        for(int i=pos,r=1;i>=0;i--)
        {
            int id=-1;
           // pf("-- %d %llu\n",r,a[r]);
//            for(int j=63;j>=0;j--)
//             if(valid(a[r],j)) pf("1");
//
//            else pf("0");
            if(valid(a[r],i))//a[r] er i tomo position e 1 ache ki?
            {
              id=r;
            }
            if(id==-1)
            {
                for(int j=r+1;j<=n;j++)
                {
                    if(valid(a[j],i))
                    {
                        id=j; break;
                    }
                }
            }
            if(id==-1) continue; //ei element ke baad deya jabena
            //ei khetre kdi ei index er uporer 1 thake tahole thakteo pare. bt niche nei. amra niche ache kina dekhe kaj kori
            u64 tmp;
            {
              swap(a[id],a[r]);
              tmp=a[r];
            }
//            cout<<tmp,pfn;

            for(int j=1;j<=n;j++)
            {
                if(j!=r)
                if(valid(a[j],i)==true) a[j]=a[j]^tmp;
            }

//            for(int k=1;k<=n;k++)
//              {
//                   for(int j=63;j>=0;j--)
//                    if(valid(a[k],j)) pf("1");
//                    else pf("0");
//                    pfn;
//              }

//            pf("%lld\n",a[r]);
//           for(int j=1;j<=n;j++) pf("%llu ",a[j]);
//           pfn;
             r++; // goto next element
        }
        u64 res=0;
      for(int i=1;i<=n;i++) if(res^a[i]>=res) res^=a[i];
      pf("%llu\n",res);
    }

    return 0;
}
