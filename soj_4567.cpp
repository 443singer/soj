#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
map<int,bool>zxr;
    const int maxn = 10001000;
    int a[maxn], x[maxn];
    int n, m, X, Y, Z;
    int NxtInt(){
    X = (X + Y) % Z;
    return X;
    }
    void Solve(){
    }
    int main(){
    scanf("%d%d%d%d", &n, &X, &Y, &Z);
    for(int i = 1; i <= n; i++)
    a[i] = NxtInt(),zxr[a[i]] = 1;
    scanf("%d%d%d%d", &m, &X, &Y, &Z);
    for(int i = 1; i <= m; i++) {
    x[i] = NxtInt();
    if(zxr[x[i]]) printf("%d\n",i);
    }
    return 0;
    }
