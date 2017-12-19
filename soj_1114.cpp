#include <cstdio>
#include <iostream>
using namespace std;
int dp[113][113];
int a[113][113];
int n;
struct hp {
    int x,y;
}pre[113][113],ans;
int main() {
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= i ; ++j) scanf("%d",&a[i][j]);
    }
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= i ; ++j) {
            dp[i][j] = a[i][j];
            if(dp[i-1][j]>dp[i-1][j-1]) {
                pre[i][j].x = i-1;
                pre[i][j].y = j;
                dp[i][j] += dp[i-1][j];
            } else {
                pre[i][j].x = i-1;
                pre[i][j].y = j-1;
                dp[i][j] += dp[i-1][j-1];
            }
            if(dp[i][j] > dp[ans.x][ans.y]) {
                ans.x = i;
                ans.y = j;
            }
        }
    }
    printf("%d\n",dp[ans.x][ans.y]);

    int haha[233],cnt = 0;
    while(ans.x!=0 && ans.y!=0) {
        haha[++cnt] = a[ans.x][ans.y];
        ans = pre[ans.x][ans.y];
    }
    for(int i = cnt ; i >= 1 ; --i) printf("%d ",haha[i]);
    printf("\n");
}

