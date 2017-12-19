#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[1003][1003];
int sumx[1003][1003];
int sumy[1003][1003];
int sum[1003][1003];
bool check(int mid,int x,int y) {
    int cnt = sum[x][y]-sum[x][y-mid]-sum[x-mid][y]+sum[x-mid][y-mid];
    if(cnt==mid*mid) return 1;
    return 0;
}
int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i = 1 ; i <= n ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                a[i][j] = sumx[i][j] = sumy[i][j] = sum[i][j] = 0;
        for(int i = 1 ; i <= m ; ++i) {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y] = 1;
        }
        for(int i = 1 ; i <= n ; ++i) {
            for(int j = 1 ; j <= n ; ++j) {
                if(!a[i][j]) sumx[i][j] = sumy[i][j] = 1;
                sumx[i][j] += sumx[i][j-1];
                sumy[i][j] += sumy[i-1][j];
            }
        }
        for(int i = 1 ; i <= n ; ++i) {
            for(int j = 1 ; j <= n ; ++j) {
                if(!a[i][j]) sum[i][j] = 1;
                sum[i][j] += sum[i-1][j-1]+sumx[i][j-1]+sumy[i-1][j];
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; ++i) {
            for(int j = 1 ; j <= n ; ++j) {
                if(a[i][j]) continue;
                int r = min(i,j);
                int l = 1;
                while(l<=r) {
                    int mid = (l+r) >> 1;
                    if(check(mid,i,j)) l = mid+1,ans = max(ans,mid);
                    else r = mid-1;
                }
            }
        }
        printf("%d\n",ans);
    }
}
