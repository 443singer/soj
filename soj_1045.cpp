#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 103;
int n,a[N],b[N],c[N],t,sum,ans,d[N];
bool dfs(int len_,int nowlen,int cnt,int st) {
    if(cnt==n) return true;
    for(int i = st ; i >= 1 ; --i) {
        if(!c[i]) continue;
        if(b[i]+nowlen<=len_) {
            c[i]--;
            int tmplen = b[i] + nowlen;
            if(tmplen==len_) tmplen = 0;
            bool flag = dfs(len_,tmplen,cnt+1,tmplen!=0?i:t);
            if(flag) return true;
            else {
                c[i]++;
                if(nowlen==0) return false;
            }
        }
    }
    return false;
}
int main() {
    while(scanf("%d",&n),n) {
        t = 0 ; sum = 0 ; ans = 0;
        for(int i = 1 ; i <= n ; ++i) {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        sort(a+1,a+1+n);
        for(int i = 1 ; i <= n ; ++i) {
            if(a[i]!=a[i-1]) b[++t] = a[i],c[t] = 0;
            c[t]++;
        }
        for(int i = a[n] ; i <= sum/2 ; ++i) {
            if(sum%i==0) {
         //       for(int j = 1 ; j <= n ; ++j) c[i] = d[i];
                if(dfs(i,0,0,t)) {
                    ans = i;
                    break;
                }
            }
        }
        if(!ans) ans = sum;
        printf("%d\n",ans);
    }
}
