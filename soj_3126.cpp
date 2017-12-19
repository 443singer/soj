#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 23;
int n,m;
int a[N];
int ans;
bool flag;
void dfs(int tmp,int l) {
    if(tmp>=m) {
        flag = true;
        ans = min(ans,tmp);
        return;
    }
    for(int i = l ; i <= n ; ++i) dfs(tmp+a[i],i+1);
}
int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]);
        ans = 1e9*2+13;
        flag = false;
        dfs(0,1);
        if(!flag) printf("-1\n");
        else printf("%d\n",ans);
    }
}
