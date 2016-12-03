#define MAX_N 1000010

char s[MAX_N],s1[MAX_N],rs[MAX_N],rs1[MAX_N];
int n,m,ls,ls1;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];


int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];
int tmps[MAX_N],tmps1[MAX_N],idx1[MAX_N],idx2[MAX_N];

void countingSort(int k)
{
  int i, sum, maxi = max(300, n);
  memset(c, 0, sizeof c);

  for (i = 0; i < n; i++)
    c[i + k < n ? RA[i + k] : 0]++;

  for (i = sum = 0; i < maxi; i++)
  {
    int t = c[i]; c[i] = sum; sum += t;
  }

  for (i = 0; i < n; i++)
    tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];

  for (i = 0; i < n; i++)
    SA[i] = tempSA[i];
}

void constructSA() {
    mem(SA,0); mem(RA,0); mem(tempRA,0);
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = s[i];
  for (i = 0; i < n; i++) SA[i] = i;
  for (k = 1; k < n; k <<= 1) {
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]] = r = 0;
    for (i = 1; i < n; i++)
      tempRA[SA[i]] =
(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;
} }


void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;
  for (i = 1; i < n; i++)
    Phi[SA[i]] = SA[i-1];
  for (i = L = 0; i < n; i++) {
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }
    while (s[i + L] == s[Phi[i] + L]) L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for (i = 0; i < n; i++)
    LCP[i] = PLCP[SA[i]];
}
int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

struct node {
	int next[26];
	int len; // ei node er palindrome length
	int sufflink; // ei node er suffix link
	int num;  //ei node e kotota palindrome ache
};

int len;
node tree[MAX_N],tree1[MAX_N];
int num; 			// node 1 - root with len -1, node 2 - root with len 0
int suff; 			// max suffix palindrome
long long ans;

bool addLetter(int pos) {
	int cur = suff, curlen = 0;
	int let = rs[pos] - 'a';
	while (true) {
		curlen = tree[cur].len;
		if (pos - 1 - curlen >= 0 && rs[pos - 1 - curlen] == rs[pos])
			break;
		cur = tree[cur].sufflink;
	}

	if (tree[cur].next[let]) {
		suff = tree[cur].next[let];
		return false;
	}

	num++; // adding new node
	suff = num;
	tree[num].len = tree[cur].len + 2;
	tree[cur].next[let] = num;
	if (tree[num].len == 1) {
		tree[num].sufflink = 2;
		tree[num].num = 1;
		return true;
	}

	while (true) {
		cur = tree[cur].sufflink;
		curlen = tree[cur].len;
		if (pos - 1 - curlen >= 0 && rs[pos - 1 - curlen] == rs[pos]) {
			tree[num].sufflink = tree[cur].next[let];
			break;
		}
	}

	tree[num].num = 1 + tree[tree[num].sufflink].num;

	return true;
}

void initTree() {
	num = 2; suff = 2;
	tree[1].len = -1; tree[1].sufflink = 1;
	tree[2].len = 0; tree[2].sufflink = 1;
}

bool addLetter1(int pos) {
	int cur = suff, curlen = 0;
	int let = rs1[pos] - 'a';
	while (true) {
		curlen = tree1[cur].len;
		if (pos - 1 - curlen >= 0 && rs1[pos - 1 - curlen] == rs1[pos])
			break;
		cur = tree1[cur].sufflink;
	}

	if (tree1[cur].next[let]) {
		suff = tree1[cur].next[let];
		return false;
	}

	num++; // adding new node
	suff = num;
	tree1[num].len = tree1[cur].len + 2;
	tree1[cur].next[let] = num;
	if (tree1[num].len == 1) {
		tree1[num].sufflink = 2;
		tree1[num].num = 1;
		return true;
	}

	while (true) {
		cur = tree1[cur].sufflink;
		curlen = tree1[cur].len;
		if (pos - 1 - curlen >= 0 && rs1[pos - 1 - curlen] == rs1[pos]) {
			tree1[num].sufflink = tree1[cur].next[let];
			break;
		}
	}

	tree1[num].num = 1 + tree1[tree1[num].sufflink].num;

	return true;
}

void initTree1() {
	num = 2; suff = 2;
	tree1[1].len = -1; tree1[1].sufflink = 1;
	tree1[2].len = 0; tree1[2].sufflink = 1;
}


int main() {
 //fout("3333.txt");
int t;
S(t);
while(t--){
       mem(tree,0);
    mem(tree1,0);
        for(int i=0;i<=200003;i++)
        {
            tmps1[i]=tmps[i]=idx1[i]=idx2[i]=0;
        }
      sc("%s",s);
      sc("%s",s1);
      ls =(int)strlen(s);
      n=ls;
      ls1 =(int)strlen(s1);
      m=ls1;

      strcpy(rs1,s1);
      strcpy(rs,s);

      int u=0;
      for(int i=ls1-1;i>=0;i--) s1[u++]=rs1[i];
      s1[u]='\0';
      strcat(s,"$");
      strcat(s,s1);
      strcat(s,"#");
      //cout<<s,pfn;
      n = (int)strlen(s);

      constructSA();                                              // O(n log n)
      computeLCP();
      int ow[200005];
  u=0;
      for(int i=ls-1;i>=0;i--) rs[u++]=s[i];
      rs[u]='\0';

      initTree();

      for(int i=0;i<ls;i++){
        addLetter(i);
      //  if(tree[suff].len==10)
          //  pf("%d %d\n",i,ls-i-1);
        idx1[i]=tree[suff].len;
        }
      int totalnode=num;
//      pf("%d -- \n",n);                                               // O(n)
//     // printf("\nThe LCP information of 'T+P' = '%s':\n", s);
//      printf("i\tSA[i]\tLCP[i]\tOwner\tSuffix\n");
//      for (int i = 0; i < n; i++)
//       if(s[SA[i]]=='b' && s[SA[i]+1]=='n' && s[SA[i]+2]=='j' && i>ls) printf("%2d\t%2d\t%2d\t%2d\t%s\n", i, SA[i], LCP[i], owner(SA[i]), s + SA[i]);

      //reverse 1st string



      initTree1();

      for(int i=0;i<ls1;i++){
        addLetter1(i);
        idx2[i]=tree1[suff].len;
        }
      int tt=ls;

      for(int i=0;i<ls;i++)
        tmps[--tt]=idx1[i];
      tt=ls1;
      for(int i=0;i<ls1;i++)
        tmps1[--tt]=idx2[i];
////
//      for(int i=0;i<ls;i++) pf("%d %d\n",i,tmps[i]);
//      pfn;
//      for(int i=0;i<ls1;i++) pf("%d %d\n",i+ls+1,tmps1[i]);

       int id1,id2,mx=-1,len1=0,len2=0,dp=2,no1=0,no2=0;
       string s2="",s3="";
       for(int i=3;i<n;i++)
       {
           int u1=owner(SA[i-1]);
         int u2=owner(SA[i]);
         if(u2==1)
         {
             int lp=LCP[i];
               for(int j=i-1;j>=0;j--)
               {

                   lp=min(LCP[j+1],lp);
                 //  if(i==10695) pf("%d %d %d\n",i,j,lp);
                   if(lp==0 || LCP[i]>lp) break; // ei position theke uporer jotokhon porjnto same lcp thake totokhon porjnto jai.
                   if(owner(SA[j])==1) continue;

               int pl=max(tmps[SA[i]+lp],tmps1[SA[j]+lp-ls-1]);
            // if(i==10695) pf("%d %d %d %d - )\n",i,j,lp,pl);
               if(pl+2*lp>mx)
               {
                   no1=i;
                   no2=j;
                   mx=pl+2*lp;
                   id2=SA[j];
                   id1=SA[i];
                   len2=lp+(tmps[SA[i]+lp]<=tmps1[SA[j]+lp-ls-1]?tmps1[SA[j]+lp-ls-1]:0);
                   len1=lp+(tmps[SA[i]+lp]>tmps1[SA[j]+lp-ls-1]?tmps[SA[i]+lp]:0);

                 //if(i==10695)  pf("- %d %d %d %d %d\n",i,len1,len2,tmps[SA[i]+lp],tmps1[SA[j]+lp-ls-1]);
               }
               else if((pl+2*lp==mx && j<no2))
               {
                   no2=j;
                   no1=i;
                   mx=pl+2*lp;
                   id2=SA[j];
                   id1=SA[i];
                   len2=lp+(tmps[SA[i]+lp]<=tmps1[SA[j]+lp-ls-1]?tmps1[SA[j]+lp-ls-1]:0);
                   len1=lp+(tmps[SA[i]+lp]>tmps1[SA[j]+lp-ls-1]?tmps[SA[i]+lp]:0);
                //   if(i==10695)  pf("-- %d %d %d %d %d\n",i,len1,len2,tmps[SA[i]+lp],tmps1[SA[j]+lp-ls-1]);
               }
               }
         }
       }
       if(mx>0){
       for(int i=id1;i<id1+len1;i++) s2+=s[i];

      for(int i=id2+len2-1;i>=id2;i--) s2+=s[i];
       }

       mx=-1,len1=0,len2=0,no1=0,no2=0;

       for(int i=3;i<n;i++)
       {
           int u1=owner(SA[i-1]);
         int u2=owner(SA[i]);
         if(u2==2 )
         {
             int lp=LCP[i];
               for(int j=i-1;j>=0;j--)
               {
                   lp=min(LCP[j+1],lp);
                  if(lp==0 || LCP[i]>lp) break;
                   if(owner(SA[j])==2) continue;

               int pl=max(tmps[SA[j]+lp],tmps1[SA[i]+lp-ls-1]);
              // if(SA[i]==63582 || SA[j]==63582) pf("%d %d %d %d - )-- \n",i,j,lp,pl);
               if(pl+2*lp>mx)
               {
                   no1=j;
                   no2=i;
                   mx=pl+2*lp;
                   id1=SA[j];
                   id2=SA[i];
                   len2=lp+(tmps[SA[j]+lp]<tmps1[SA[i]+lp-ls-1]?tmps1[SA[i]+lp-ls-1]:0);
                   len1=lp+(tmps[SA[j]+lp]>=tmps1[SA[i]+lp-ls-1]?tmps[SA[j]+lp]:0);

                // if(SA[i]==63582 || SA[j]==63582)  pf("- %d %d %d %d %d\n",i,len1,len2,tmps[SA[j]+lp],tmps1[SA[i]+lp-ls-1]);
               }
               else if((pl+2*lp==mx && j<no1))
               {
                  no1=j;
                   no2=i;
                   mx=pl+2*lp;
                   id1=SA[j];
                   id2=SA[i];
                   len2=lp+(tmps[SA[j]+lp]<tmps1[SA[i]+lp-ls-1]?tmps1[SA[i]+lp-ls-1]:0);
                   len1=lp+(tmps[SA[j]+lp]>=tmps1[SA[i]+lp-ls-1]?tmps[SA[j]+lp]:0);
                  // if(SA[i]==63582 || SA[j]==63582) pf("-- %d %d %d %d %d\n",i,len1,len2,tmps[SA[j]+lp],tmps1[SA[i]+lp-ls-1]);
               }
               }
         }
       }
       if(mx>0){
       for(int i=id1;i<id1+len1;i++) s3+=s[i];

      for(int i=id2+len2-1;i>=id2;i--) s3+=s[i];
       }
  if(s2.size()==0 && s3.size()==0) pf("-1");
  else
  {
      if(s2.length()>s3.length()) cout<<s2;
      else if(s2.length()<s3.length()) cout<<s3;
      else {
    if(s2>s3) swap(s2,s3);
    if(s2.size()!=0) cout<<s2;
    else cout<<s3;}
  }
pfn;
}
  return 0;
}
