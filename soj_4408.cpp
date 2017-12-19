#include <cstdio>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1003;
char a[13][N],b[N];
int n,T,k;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        while(n--) {
            memset(a,0,sizeof(a));
            scanf("%s",b+1);
            int x = 1 , y = 1;
            int nowd = 1;
            a[x][y] = b[1];
            int len = strlen(b+1);
            for(int i = 2 ; i <= len ; ++i) {
                if(nowd) {
                    x++;
                } else {
                    x--;y++;
                }
                a[x][y] = b[i];
                if(i==k||(i-1)%(k-1)==0) nowd ^= 1;
            }
            for(int i = 1 ; i <= k ; ++i)
                for(int j = 1 ; j <= len ; ++j)
                    if(a[i][j]) printf("%c",a[i][j]);
            printf("\n");
        }
    }
}
