#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 13;
int n,a[N],b[N],ans;
void dfs(int d) {
    if(d>n) {
        ans++;
        return;
    }
    if(b[d]) {
        a[d] = b[d];
        if(d>1) {
            if(abs(a[d]-a[d-1]) <= 1) dfs(d+1);
        } else dfs(d+1);
        return;
    }
    for(int i = 1 ; i <= n ; ++i) {
        if(d==1) {
            a[d] = i;
            dfs(d+1);
        } else if(abs(i-a[d-1])<=1) {
            a[d] = i;
            dfs(d+1);
        }
    }
}
int main() {
    while(scanf("%d",&n),n) {
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&b[i]);
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
}
