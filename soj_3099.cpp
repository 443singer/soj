#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+23;
struct tr1 {
    tr1* ls;
    tr1* rs;
    long long sum,lazy;
    tr1() {
        ls = rs = NULL;
        sum = lazy = 0;
    }
}*root,dizhi[N*20];
int t;
int n,m,a[N];
void build(tr1* tr,int l,int r) {
    if(l==r) {
        tr->sum = a[l];
        tr->lazy = 0;
        return;
    }
    int mid = (l+r) >> 1;
    tr->ls = &dizhi[++t];
    tr->rs = &dizhi[++t];
    build(tr->ls,l,mid);
    build(tr->rs,mid+1,r);
    tr->sum = tr->ls->sum + tr->rs->sum;
    tr->lazy = 0;
}
void push_down(tr1* tr,int l,int r) {
    if(!tr->lazy) return;
    int mid = (l+r) >> 1;
    tr->ls->sum += (mid-l+1)*tr->lazy;
    tr->rs->sum += (r-mid)*tr->lazy;
    tr->ls->lazy += tr->lazy;
    tr->rs->lazy += tr->lazy;
    tr->lazy = 0;
}
void modify(tr1* tr,int l,int r,int x,int y,long long z) {
    if(l!=r) push_down(tr,l,r);
    if(x<=l && r<=y) {
        tr->sum += (r-l+1)*z;
        tr->lazy += z;
        return;
    }
    int mid = (l+r) >> 1;
    if(!(x>mid || y<l)) modify(tr->ls,l,mid,x,y,z);
    if(!(x>r||y<mid+1)) modify(tr->rs,mid+1,r,x,y,z);
    tr->sum = tr->ls->sum + tr->rs->sum;
}
long long query(tr1* tr,int l,int r,int x,int y) {
    if(l!=r) push_down(tr,l,r);
    if(x<=l && r<=y) return tr->sum;
    int mid = (l+r) >> 1;
    long long tmp_sum = 0;
    if(!(x>mid || y<l)) tmp_sum += query(tr->ls,l,mid,x,y);
    if(!(x>r||y<mid+1)) tmp_sum += query(tr->rs,mid+1,r,x,y);
    return tmp_sum;
}
char q[23];
int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        t = 0;
        root = &dizhi[++t];
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]);
        build(root,1,n);
        for(int i = 1 ; i <= m ; ++i) {
            int x,y;
        long long z;
            scanf("%s",q);
            scanf("%d%d",&x,&y);
            if(q[0]=='Q') {
                printf("%lld\n",query(root,1,n,x,y));
            } else {
                scanf("%lld",&z);
                modify(root,1,n,x,y,z);
            }
        }
    }
}
