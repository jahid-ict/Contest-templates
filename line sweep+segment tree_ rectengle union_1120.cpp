struct T
{
    int x,y1,y2,active;
    bool operator<(const T& p)
    const {return x<p.x;}
}edges[60005];
int t,co,yt,ryt,tot,n,a,b,c,d,rycrd[4*30005],ycrd[4*30005];
i64 tree[16*30005],oc[16*30005];
i64 res=0;

void update(int node, int b, int e, int y1, int y2, int actv)
{
    if(ycrd[b]>y2 || ycrd[e]<y1) return ;
    int mid=(b+e)/2;
    int left=2*node;
    int rigt=left+1;
    if(ycrd[b]>=y1 && ycrd[e]<=y2)
    {
        oc[node]+=(actv==1)?1:-1;
        if(oc[node]>0) tree[node]=ycrd[e]-ycrd[b];
        //overlap hole ami jdi ekta ke rmv kore dei then no problem
        //cz oc not zero jotokhon sobgula not remvd.
        else tree[node]=tree[left]+tree[rigt];
        return;
    }
    if(b+1>=e) return;//3==3 er kono drkr nei krar
    update(left,b,mid,y1,y2,actv);
    update(rigt,mid,e,y1,y2,actv);
    if(oc[node]>0) tree[node]=ycrd[e]-ycrd[b];//recursion er vitor kothao hteo pare
    else tree[node]=tree[left]+tree[rigt];
    return;
}
int main()
{
    /*
    ekahne ami line sweep + segment tree use korechi.
    ami top-down line seep korechi.
    ekhane array er value er somotullo niyechi y coordinates ke.
    then prothome same x axis er jnne update. then porer axis
    e value add res er sathe. jdi eta kono rect er shes pranto hoy tahole
    -1 diye ei edge ke tree er sum theke minus.
    */
    S(t);
    while(t--)
    {
        S(n);
        tot=0;
        ryt=0;
        repc(i,1,n)
        {
            S2(a,b); S2(c,d);
            edges[++tot].x=a;edges[tot].y1=b;edges[tot].y2=d; edges[tot].active=1;
            edges[++tot].x=c;edges[tot].y1=b;edges[tot].y2=d; edges[tot].active=-1;
            rycrd[++ryt]=b;
            rycrd[++ryt]=d;
        }
        yt=1;
        sort(rycrd+1,rycrd+ryt+1);
        ycrd[1]=rycrd[1];
        for(int i=2;i<=ryt;i++)
        {
          if(ycrd[yt]!=rycrd[i]) ycrd[++yt]=rycrd[i];
        }
        sort(edges+1,edges+tot+1);
        res=0;
        mem(tree,0);
        mem(oc,0);
        update(1,1,yt,edges[0].y1,edges[0].y2,edges[0].active);
        for(int i=1;i<=tot;i++)
        {
            res+=((edges[i].x-edges[i-1].x)*tree[1]);
            update(1,1,yt,edges[i].y1,edges[i].y2,edges[i].active);
        }
        pf("Case %d: %lld\n",++co,res);
    }
    return 0;
}
