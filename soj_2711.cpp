#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF) {
        printf("%d\n",((n/m+1)*m-n)%m);
    }
}
