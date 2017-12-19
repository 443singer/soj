#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1003;
const int M = 1003*1003;
struct hhp {
    int x,y,d;
}a[M];
int T,n,m;
int fa[N];
int find(int x) {return x==fa[x]?x:fa[x] = find(fa[x]);}
void uunion(int x,int y) {
    x = find(x) ; y = find(y);
    if(x!=y) fa[x] = fa[y];
}
bool cmp(hhp aa,hhp bb) {
    return aa.d>bb.d;
}
int main() {
    scanf("%d",&T);
    for(int tt = 1 ; tt <= T ; ++tt) {
        scanf("%d%d",&n,&m);
        for(int i = 1 ; i <= m ; ++i) {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].d);
        }
        for(int i = 1 ; i <= n ; ++i) fa[i] = i;
        sort(a+1,a+1+m,cmp);
        int t = 0;
        while(t<m) {
            t++;
            uunion(a[t].x,a[t].y);
            if(find(1)==find(n))break;
        }
        printf("Scenario #%d:\n",tt);
        if(t<=m) printf("%d\n\n",a[t].d);
        else printf("0\n\n");
    }
}
