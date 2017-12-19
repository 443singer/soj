#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+13;
int c[N],a[N];
int n,m;
int lowbit(int x) {return x&(-x);}
void modify(int x,int add) {
    while(x<=n) {
        c[x] += add;
        x += lowbit(x);
    }
}
int query(int x) {
    int tmp = 0;
    while(x) {
        tmp += c[x];
        x -= lowbit(x);
    }
    return tmp;
}
int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        for(int i = 1 ; i <= m ; ++i) {
            int b,p,q;
            scanf("%d%d%d",&b,&p,&q);
            if(b==0) {
                q++;p++;
                printf("%d\n",query(q)-query(p-1));
            } else {
                p++;
                modify(p,q);
            }
        }
    }
}
