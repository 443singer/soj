#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1003;
struct hp {
    int a,b;
}h[N];
int n,v;
bool cmp(hp x,hp y) {return x.b-x.a>y.b-y.a;}
int main() {
    while(scanf("%d%d",&v,&n)!=EOF) {
        for(int i = 1 ; i <= n ; ++i) scanf("%d%d",&h[i].a,&h[i].b);
        sort(h+1,h+1+n,cmp);
        bool flag = true;
        for(int i = 1 ; i <= n ; ++i) {
            if(v-h[i].b<0) {
                flag = false;
                break;
            }
            v -= h[i].a;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
