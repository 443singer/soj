#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100003;
int a[N];
bool cmp(int a,int b) {
    int add = 1;
    int t = a;
    while(t) {
        add*=10;
        t/=10;
    }
    int tmp1 = b*add+a;
    add = 1;
    t = b;
    while(t) {
        add*=10;
        t/=10;
    }
    int tmp2 = a*add+b;
    return tmp1<tmp2;
}
int main() {
    int T = 0,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]);
        sort(a+1,a+1+n,cmp);
        for(int i = 1 ; i <= n ; ++i) printf("%d",a[i]);
        if(T) printf("\n");
    }
}
