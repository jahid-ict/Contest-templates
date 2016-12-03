int Lo[200005],C,R,Left,N,expand,diff,maxcenter,maxlength,st,en;
char s[100002];

void manachers(char *s, int N)
{
    N=2*N+1;
    Lo[0]=0;Lo[1]=1;
    C=1;
    R=2;
    expand=0;
    maxcenter=1;
    maxlength=1;
    for(int i=2;i<N;i++) //i=currRightPositon
    {
      Left=2*C-i;
      expand=0;
      diff=R-i;
      if(diff>0)
      {
          if(Lo[Left]<diff)
          {
              Lo[i]=Lo[Left];
          }
          else if(Lo[Left]==diff && i==N-1)
          {
              Lo[i]=Lo[Left];
          }
          else if(Lo[Left]==diff && i<N-1)
          {
              Lo[i]=Lo[Left];
              expand=1;
          }
          else if(Lo[Left]>diff)
          {
              Lo[i]=diff;
              expand=1;
          }
      }
      else
      {
        Lo[i]=0;
        expand=1;
      }
      if(expand==1)
      while((i+Lo[i]<N && i-Lo[i]>0) && (((i+Lo[i]+1)%2==0) || (s[(i+Lo[i]+1)/2]==s[(i-Lo[i]-1)/2])))
            Lo[i]++;
      if(Lo[i]>maxlength)
      {
          maxcenter=i;
          maxlength=Lo[i];
        //  pf("%d %d\n",i,Lo[i]);
         //  pf("- %d %d\n",maxcenter,maxlength);
      }
      if(i+Lo[i]>R)
      {
          C=i;
          R=i+Lo[i];
      }
    }
    //pf("- %d %d\n",maxcenter,maxlength);
    st=(maxcenter-maxlength)/2;
    en=st+maxlength-1;
    for(int i=0;i<=N;i++)
        pf("%d ",Lo[i]);
    pfn;
    for(int i=st;i<=en;i++) pf("%c",s[i]);
}
int main()
{
    SC(s);
    N=strlen(s);
    manachers(s,N);
    return 0;
}
