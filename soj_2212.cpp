#include <cstdio>
#include <iostream>
using namespace std;
int n,k,ans;
void dfs(int butt,int k) {
    if(butt < k) return;
    ans += butt/k;
    dfs(butt%k+butt/k,k);
}
int main() {
    while(scanf("%d%d",&n,&k)!=EOF) {
        ans = n;
        dfs(n,k);
        printf("%d\n",ans);
    }
}    
