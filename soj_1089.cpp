#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 103;
const int M = 1003;
bool zxr[M];
int n,m,a[N];
int main() {
    while(scanf("%d%d",&n,&m)==2) {
        if(n==0) break;
        int ans = 0;
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]),zxr[a[i]] = 1;
        sort(a+1,a+1+n);
        for(int i = 1 ; i <= n ; ++i) {
            for(int j = i + 1 ; j <= n ; ++j) {
                int k = m-a[i]-a[j];
                if(zxr[k] && k>a[j]) ans++;
            }
        }
        printf("%d\n",ans);
    }
}
