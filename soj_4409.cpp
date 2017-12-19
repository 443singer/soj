#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 1000003;
struct hp {
    int cnt,val;
}f[N];
hp min(hp a,hp b) {
    if(a.cnt==b.cnt) return a.val < b.val?a:b;
    return a.cnt<b.cnt?a:b;
}
int to[2] = {4,7},E[2] = {1,1000000/4};
void spfa() {
    memset(f,0x3f,sizeof(f));
    f[0].cnt = f[0].val = 0;
    for(int i = 1 ; i <= 1000000 ; ++i) {
        for(int j = 0 ; j < 2 ; ++j) {
            if(i-to[j]<0) continue;
            hp newf;
            newf.cnt = f[i-to[j]].cnt+1;
            newf.val = f[i-to[j]].val+E[j];
            f[i] = min(f[i],newf);
        }
    }
}
int main() {
    spfa();
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
                if(f[n].cnt>E[1]) {
            printf("-1\n");
            continue;
        }
        int four_ = f[n].val%E[1];
        int seven_ = f[n].val/E[1];
        for(int i = 1 ; i <= four_ ; ++i) printf("4");
        for(int j = 1 ; j <= seven_ ; ++j) printf("7");
        printf("\n");
    }
}

