#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 103;
const int INF = -127*1000000;
int T,n,m;
int a[N][N],b[N][N],ans;
int main() {
    scanf("%d",&T);
    while(T--) {
        ans = INF;
          scanf("%d%d",&n,&m);
            for(int i = 1 ; i <= n ; ++i)
                   for(int j = 1 ; j <= m ; ++j)
                        scanf("%d",&a[i][j]),b[i][j] = b[i][j-1]+a[i][j];
            for(int i = 1 ; i <= n ; ++i)
                for(int j = i ; j <= m ; ++j) {
                        int tmp = INF;
                        for(int k = 1 ; k <= n ; ++k) {
                            int now = b[k][j]-b[k][i-1];
                            if(tmp<0) tmp = now;
                            else tmp = tmp+now;
                            ans = max(ans,tmp);
                        }
                }
            printf("%d\n",ans);
    }
}
