#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 50;
int T,n,a[N],b[N],dp[N],pre[N],pos[N];
bool vis[N];
int main() {
    scanf("%d",&T);
    while(T--) {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]),b[i] = a[i],pos[i] = i;
        int cnt = 0;
        int pai = 0;
        while(cnt!=n) {
            pai++;
            memset(dp,0,sizeof(dp));
            memset(pre,0,sizeof(pre));
            int tmpans = 0;
            for(int i = 1 ; i <= n-cnt ; ++i) {
                dp[i] = 1;
                int linshi = 0;
                for(int j = 1 ; j < i ; ++j) {
                    if(b[j] >= b[i]) {
                        linshi = max(linshi,dp[j]);
                        pre[i] = j;
                    }
                }
                dp[i] += linshi;
                if(dp[i]>dp[tmpans]) {
                    tmpans = i;
                }
            }
            if(!cnt) printf("%d ",dp[tmpans]);
            cnt += dp[tmpans];
            while(tmpans) {
                vis[pos[tmpans]] = 1;
                tmpans = pre[tmpans];
            }
            int t = 0;
            for(int i = 1 ; i <= n ; ++i) {
                if(!vis[i]) b[++t] = a[i],pos[t] = i;
            }
        }
        printf("%d\n",pai);
    }
}
