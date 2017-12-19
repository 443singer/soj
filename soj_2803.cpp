#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 100003;
int a[2*N],n,T;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; ++i) {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i] = x-y;
            a[i+n] = a[i];
        }
        int h = 1,t = 0,sum = 0;
        while(h<=n && a[h]<0) h++;
        t = h;
        sum = a[h];
        while(t-h!=n && h<=n) {
            t++;
            if(sum+a[t]>=0) {
                sum += a[t];
                continue;
            }
            while(sum+a[t]<0 && h<=t) sum -= a[h++];
            if(h>t) {
                while(h<=n && a[h]<0) h++;
                t = h;
                sum = a[h];
            }
        }
        if(h<=n) printf("%d\n",h-1);
        else printf("-1\n");
    }
}
