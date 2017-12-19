#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000013;
int a[N],n,b[N],ans;
int main() {
    while(scanf("%d",&n)!=EOF) {
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]);
        ans = 1;
        b[1] = a[1];
        for(int i = 2 ; i <= n ; ++i) {
            int l = 1 , r = ans;
            int tmp = 0;
            while(l<=r) {
                int mid = (l+r) >> 1;
                if(b[mid]<a[i]) l = mid+1,tmp = max(tmp,mid);
                else r = mid-1;
            }
            if(tmp==ans) b[++ans] = a[i];
            else if(a[i]<b[tmp+1]) b[tmp+1] = a[i];
        }
        printf("%d\n",ans);
    }
}
