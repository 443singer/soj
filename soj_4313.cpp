#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100003;
int first[N],next_[N*2],to[N*2],eg;
inline void addedge(int x,int y) {
    next_[++eg] = first[x];
    first[x] = eg;
    to[eg] = y;
}
inline void add(int x,int y) {
    addedge(x,y);
    addedge(y,x);
}
int T;
int n,k,size[N],cnt;
void dfs(int u,int fa) {
    size[u] = 1;
    for(int i = first[u] ; i ; i = next_[i]) {
        if(to[i]==fa) continue;
        dfs(to[i],u);
        size[u] += size[to[i]];
    }
    if(size[u]%k==0) cnt++;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        eg = 0;
        memset(first,0,sizeof(first));
        for(int i = 1 ; i < n ; ++i) {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
        }
        cnt = 0;
        dfs(1,0);
        if(cnt==n/k) printf("YES\n");
        else printf("NO\n");
    }
}
