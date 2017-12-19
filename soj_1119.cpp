#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 40;
const int M = 10;
long long dp[N][M];
int T,n,m;
int main() {
    scanf("%d",&T);
    while(T--) {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        dp[1][1] = dp[1][0] = 1;
        for(int i = 2 ; i <= n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                if(j) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    for(int k = 0 ; k < m ; ++k)
                        dp[i][j] += dp[i-1][k];
                }
            }
        }
        long long ans = 0;
        for(int i = 0 ; i < m ; ++i) ans += dp[n][i];
        cout << ans ;
        if(T) cout << endl;
    }
}
