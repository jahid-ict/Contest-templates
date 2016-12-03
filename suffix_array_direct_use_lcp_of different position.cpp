#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;

#define MAX_N 100010
char T[MAX_N],P[MAX_N];
int n,RA[MAX_N],tempRA[MAX_N],SA[MAX_N],m,tempSA[MAX_N],c[MAX_N],Phi[MAX_N],PLCP[MAX_N],LCP[MAX_N];
int dp[MAX_N][22];
int pos[MAX_N];

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
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];
  for (i = 0; i < n; i++) SA[i] = i;
  for (k = 1; k < n; k <<= 1) {
    countingSort(k);

    countingSort(0);
    tempRA[SA[0]] = r = 0;
    for (i = 1; i < n; i++)
      tempRA[SA[i]] =(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k])?r:++r;
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
    while (T[i + L] == T[Phi[i] + L]) L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for (i = 0; i < n; i++)
    LCP[i] = PLCP[SA[i]];
}

void sparse_table()
    {
        for(int i=0;i<=n;i++) dp[i][0]=i;

        for (int j=1; (1 << j) <= n; j++)
            for (int i = 0; i+(1 << j)-1<n; i++)
                dp[i][j] = (LCP[ dp[i][j-1] ]<=LCP[ dp[ i+(1<<(j-1))][j-1] ])? dp[i][j]=dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }

int find_lcp(int start,int end)
{
    if(start==end) return n-start-1; //special case
    start=pos[start];end=pos[end];
    if(start>end) swap(start,end);start++;
    int diff=end-start;
    diff=31 - __builtin_clz(diff+1);
    return LCP[dp[start][diff]]<=LCP[dp[end-(1<<diff)+1][diff]]?LCP[dp[start][diff]]:LCP[dp[end-(1<<diff)+1][diff]];
}


int main() {
  scanf("%s",&T);
  strcat(T,"$");
  n=strlen(T);
  constructSA();                                              // O(n log n)

  printf("i\tSA[i]\tSuffix\n");
  for (int i = 0; i < n; i++) printf("%2d\t%2d\t%s\n", i, SA[i], T + SA[i]);
  computeLCP();                                                     // O(n)
  printf("\n\nThe lcp:\n\n");
  for(int i=0;i<n;i++)
  printf("%s %d\n",T+SA[i],LCP[i]);
 ////////////////////////////////// LCP of different position
 sparse_table();
  printf("LCP++++   === %d\n",find_lcp(2,2));printf("\n");

  return 0;
}

