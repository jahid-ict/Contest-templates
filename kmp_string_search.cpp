#include<cstdio>
#include<cstring>
char s[100000],w[100000];
int t[100000],l,lw;

void find_T()
{
    int pos=2,cmd=0;
    while(pos<lw)
    {
        if(w[pos-1]==w[cmd])
        {
            cmd++; t[pos]=cmd; pos++;
        }
        else if(cmd>0) cmd=t[cmd];
        else {t[pos]=0; pos++;}
    }
}
int kmp()
{
    int m=0,i=0;
    while(m+i<l)
    {
        printf("%d %d\n",m,i);
        if(s[m+i]==w[i])
        {
            if(i==lw-1) return m;
            i++;
        }
        else
        {
            m=m+i-t[i];
            if(t[i]>-1) i=t[i];
            else i=0;
        }
    }
    return l;
}
int main()
{
    int ind=0;
    t[0]=-1;t[1]=0;
    gets(s);
    gets(w);
    l=strlen(s);
    lw=strlen(w);
    find_T();
    ind=kmp();
    if(ind<l) printf("Found at: %d\n",ind);
    else printf("Not Found.\n");
    return 0;
}
