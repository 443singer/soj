#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        int x;
        bool flag = true;
        for(int i = 1 ; i <= n ; ++i) {
            scanf("%d",&x);
            int s = sqrt(x);
            if(s*s!=x) flag = false;
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
}
