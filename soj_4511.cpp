#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 2003;
const int maxk = 3003;
int dp[maxn][2][maxk];
int a[2][maxn];
int main() {
    int n,T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; ++i) scanf("%d%d",&a[0][i],&a[1][i]);
        memset(dp,0x3f,sizeof(dp));
        dp[1][0][0] = dp[1][1][0] = 0;
        for(int i = 1 ; i < n ; ++i) {
               for(int j = 0 ; j < 2 ; ++j) {
                   for(int k = 0 ; k <= 3000 ; ++k) {
                       dp[i+1][j][max(k-a[j][i],0)] = min(dp[i+1][j][max(k-a[j][i],0)],dp[i][j][k]+a[j][i]);
                       dp[i+1][j^1][max(a[j][i]-k,0)] = min(dp[i+1][j^1][max(a[j][i]-k,0)],dp[i][j][k]+k);
                   }
               }
        }
        int ans = 1e9;
        for(int k = 0 ; k <= 3000 ; ++k) {
            for(int j = 0 ; j < 2 ; ++j) {
                int tmp = dp[n][j][k] + max(a[j][n],k);
                ans = min(ans,tmp);
            }
        }
        printf("%d\n",ans);
    }
}
