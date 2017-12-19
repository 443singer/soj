#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1003;
struct hp {
    int l,r;
}a[N];
bool cmp(hp x,hp y) { return x.r<y.r;}
int n;
int dp[N];
int main() {
    while(scanf("%d",&n)==1) {
        if(!n) break;
        memset(dp,0,sizeof(dp));
        for(int i = 1 ; i <= n ; ++i) scanf("%d%d",&a[i].l,&a[i].r);
        sort(a+1,a+1+n,cmp);
        int ans = 0;
        for(int i = 1 ; i <= n ; ++i) {
            dp[i] = 1;
            int tmp = 0;
            for(int j = 1 ; j < i ; ++j) {
                if(a[j].r<=a[i].l) tmp = max(tmp,dp[j]);
            }
            dp[i] += tmp;
            ans = max(ans,dp[i]);
        }
        cout << ans << endl;
    }    
}
