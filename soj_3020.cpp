#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1<<20;
bool vis[N+13];
long long jc[23];
long long ans1[N+13],ans2[N+13];
int main() {
    jc[1] = 1;
    for(int i = 1 ; i <= N ; ++i) ans2[i] = 1;
    for(int i = 2 ; i <= 20 ; ++i) jc[i] = jc[i-1]*i;
    for(int i = 2 ; i <= N ; ++i) {
        if(!vis[i]) {
            for(int j = 2 ; i*j <= N ; ++j) {
                int tmp = i*j;
                vis[tmp] = 1;
                int cnt = 0;
                while(tmp%i==0 && tmp!=1) {
                    cnt++;
                    tmp/=i;
                }
                ans2[i*j] *= jc[cnt];
                ans1[i*j] += cnt;
            }
        }
    }
    int x;
    while(scanf("%d",&x)!=EOF) {
        if(x==1) {
            printf("0 1\n");
            continue;
        }
        if(!vis[x]) {
            printf("1 1\n");
            continue;
        }
        cout << ans1[x] << " ";
        cout << jc[ans1[x]]/ans2[x] << endl;
    }
}
