#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1003;
long long dp[N][13];
int a[10] = {1000,400,200,100,40,20,10,4,2,1};
bool flag = false;
long long dfs(int n,int u) {
    if(n==0) return 1;
    for(int i = u ; i < 10 ; ++i) {
        if(n-a[i]>=0) {
            if(dp[n-a[i]][i]) dp[n][u] += dp[n-a[i]][i];
            else dp[n][u] += dfs(n-a[i],i);
        }
    }
    return dp[n][u];
}
int main() {
    for(int i = 1 ; i <= 1000 ; ++i)
        dfs(i,0);
    double x;
    while(cin>>x) {
        if(x-0.00<1e-4) break;
        int haha = x;
        int cnt2 = 0;
        while(haha) {
            cnt2++;
            haha /= 10;
        }
        if(cnt2!=2) printf(" ");
        printf("%.2lf",x);
        x*=100;
        int n = x;
        if(n==0) break;
        n /= 5;
        long long tmp = dp[n][0];
        int cnt = 0;
        while(tmp) {
            cnt++;
            tmp /= 10;
        }
        for(int i = 1 ; i <= 12-cnt ; ++i) {
            printf(" ");
        }
        cout << dp[n][0] << endl;
    }
}
