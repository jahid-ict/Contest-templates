#include<cstdio>
#include<cstring>
char s[1000005],w[1000005];
int t[1000005],l,lw,count,m,i,tst,co;

void find_T()
{
    t[0]=-1;t[1]=0;
    int pos=2,cmd=0;
    while(pos<=lw)
    {
        if(w[pos-1]==w[cmd])
        {
            cmd++; t[pos]=cmd; pos++;
        }
        else if(cmd>0) cmd=t[cmd];
        else {t[pos]=0; pos++;}
    }
}
void kmp()
{
    count=0;
    m=0,i=0;
    while(m+i<l)
    {
        if(s[m+i]==w[i])
        {
            if(i==lw-1)
            {
            count++;
            }
            i++;
        }
        else
        {
            m=m+i-t[i];
            if(t[i]>-1) i=t[i];
            else i=0;
        }
    }
}
int main()
{
    scanf("%d",&tst);
    getchar();
    while(tst--)
    {
    gets(s);
    gets(w);
    l=strlen(s);
    lw=strlen(w);
    find_T();
    kmp();
    printf("Case %d: %d\n",++co,count);
    }
    return 0;
}
