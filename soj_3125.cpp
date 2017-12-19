#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
int n,m;
int a[N];
int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int sum = 0;
        bool flag = false;
        for(int i = n ; i >= 1 ; --i) {
            sum+=a[i];
            if(sum>=m) {
                printf("%d\n",n-i+1);
                flag = true;
                break;
            }
        }
        if(!flag) printf("%d\n",-1);
    }
}
