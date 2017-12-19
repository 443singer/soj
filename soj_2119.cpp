#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int a[10][10];
int b[10];
int ans = 1e7;
void dfs(int dep) {
    if(dep>n) {
        int tmp = -1e7;
        for(int j = 0 ; j < n ; ++j) {
            int tmp2 = 0;
            for(int i = 0 ; i < n ; ++i) {
                tmp2 += a[i][(j+b[i])%n];    
            }
            tmp = max(tmp2,tmp);
        }
        ans = min(ans,tmp);
        return;
    }
    for(int i = 0 ; i < n ; ++i) {
        b[dep-1] = i;
        dfs(dep+1);
    }
}
int main() {
    while(scanf("%d",&n),n!=-1) {
        ans = 1e7;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                scanf("%d",&a[i][j]);
        dfs(2);
        printf("%d\n",ans);
    }
}
