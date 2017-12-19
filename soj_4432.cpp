#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int T,x;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&x);
        int cnt = 1;
        while(x) {
                    if(x&1) cnt++;
            else break;
            x>>=1;
        }
        printf("%d\n",cnt);
    }
}
