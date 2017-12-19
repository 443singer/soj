#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2003;
struct blocks {
    int x,y,h;
}a[N*10];
int n;
bool cmp(blocks a,blocks b) {
    if(a.x<b.x) return 1;
    if(a.x>b.x) return 0;
    return a.y<b.y;
}
int dp[N*10];
int main() {
    int CC = 0;
    while(scanf("%d",&n),n) {
        CC++;
        for(int i = 1 ; i <= n ; ++i) {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);
            a[i+n].x = a[i].y;a[i+n].y = a[i].x;a[i+n].h = a[i].h;
            a[i+2*n].x = a[i].h;a[i+2*n].y = a[i].y;a[i+2*n].h = a[i].x;
            a[i+3*n].x = a[i].y;a[i+3*n].y = a[i].h;a[i+3*n].h = a[i].x;
            a[i+4*n].x = a[i].h;a[i+4*n].y = a[i].x;a[i+4*n].h = a[i].y;
            a[i+5*n].x = a[i].x;a[i+5*n].y = a[i].h;a[i+5*n].h = a[i].y;
        }
        n*=6;
        sort(a+1,a+1+n,cmp);
        int ans = 0;
        for(int i = 1 ; i <= n ; ++i) {
            dp[i] = a[i].h;
            int tmp = 0;
            for(int j = 1 ; j < i ; ++j) {
                if(a[j].x<a[i].x && a[j].y<a[i].y) tmp = max(tmp,dp[j]);
            }
            dp[i] += tmp;
            ans = max(ans,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",CC,ans);
    }
}
