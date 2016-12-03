//LCA using sparse table technique
//Complexity: O(NlgN,lgN) -- NlgN for sparse table.. logn for each query
#define MX 100002
int L[MX]; //Level
int T[MX]; //immediate parent
int P[MX][22];
vector<int>edges[MX];

void dfs(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<(int)edges[u].size();i++)
    {
        int v=edges[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q) //N=total node
  {
      int tmp,log,i;
      if (L[p]<L[q])
          tmp=p,p=q,q=tmp;

      log=1;
      while(1)
      {
        int next=log+1;
        if((1<<next)>L[p])break; //EKDOM koto powe porjnto jete pari
        log++;
      }
      //cout<<log,pfn;
      for (i=log;i>=0;i--)
      if (L[p]-(1<<i)>=L[q])
          p=P[p][i];

      if (p==q)  //already done?
          return p;
 //pfn;pfn;
      for(i=log;i>=0;i--)
      {
          //cout<<i<<" "<<log<<" "<<p<<" "<<P[p][i]<<" "<<P[q][i]<<" "<<q ,pfn;;
          if(P[p][i]!=-1 && P[p][i]!=P[q][i])
              {
                 // cout<<p<<" "<<i<<" "<<q,pfn;
                  p=P[p][i],q=P[q][i];
              }
      }

      return T[p];
  }

void lca_init(int N)
  {
      memset (P,-1,sizeof(P)); //first all parent are -1
      int i,j;
       for (i=0;i<N;i++) //1-N
          P[i][0]=T[i];

      for (j=1;1<<j < N;j++)
         for (i=0;i<N;i++) //1-N
             if (P[i][j-1]!=-1)
                 P[i][j]=P[P[i][j-1]][j-1];
 }

int main()
{
    ///zero based index
//	edges[0].pb(1);
//	edges[0].pb(2);
//	edges[2].pb(3);
//	edges[2].pb(4);
edges[0].pb(1);
edges[1].pb(2);
edges[2].pb(3);
edges[3].pb(4);
edges[4].pb(5);
edges[5].pb(6);
edges[5].pb(7);
edges[6].pb(8);
edges[7].pb(9);
	dfs(-1,0,0);//-1,1,0//jehetu root node er parent hbe -1
	lca_init(10);//10=Total node
	printf("%d\n",lca_query(10,8,9)); // total nodes(n),nodes
	return 0;
}
