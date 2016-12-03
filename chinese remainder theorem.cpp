#define MAXN 100005
/*
suppose x=a1%m1; x=a2%m2; x=a[i]%m[i];
m=m1*m2*..*m[i];
Now, We need to find x where m[i] are the prime and a[i] are the remainders.
according to chinese remainder theorem,
x=a1*M1*y1+a2*M2*y2+...
m=m[1]*m[2]*m[3]....
where M[i]=m/m[i];
y[i]=inverse of M[i]%m[i]; M[i]*y[i]=1(mod m[i]);
i
now, vag na kore ami multiplicative inverse ber kore felbo extended euclid use kore;
jdi m[i] ta prime hoy tahole bigmod die e kora jay ar na hoy euclid proyojon.
*/
int main()
{
     int t,n,i,p[13],r[13],co=0;
     scanf("%d",&t);
     long long int tot,ret,mul;
     while(t--)
     {
         mul=1;
          tot=0;
         scanf("%d",&n);
         for(i=1;i<=n;i++){
         scanf("%d %d",&p[i],&r[i]); mul*=p[i];}
         for(i=1;i<=n;i++)
         {
             tot=tot+(r[i]*modinverse((i64)mul/p[i],(i64)p[i])*(mul/p[i]));
         }
         printf("Case %d: %lld\n",++co,tot%mul);
     }
    return 0;
}
