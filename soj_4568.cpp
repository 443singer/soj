#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 10001000;
const int mod = 6e7+11;
int hash_[maxn*6];
int n, m, X, Y, Z;
long long lucky(int x) {return 2ll*x*x+2ll*x+23333;}
void insert(int x) {
    long long tmp = lucky(x);
    int u = x;
    int jump = 1;
    if(u&1) jump *= -1;
    x = tmp%mod;
    while(hash_[x]) {
        x += jump;
        x = (x+mod)%mod;
    }
    hash_[x] = u;
}
bool query(int x) {
    long long tmp = lucky(x);
    int u = x;
    int jump = 1;
    if(u&1) jump *= -1;
    x = tmp%mod;
    while(hash_[x]!=u && hash_[x]) {
        x += jump;
        x = (x+mod)%mod;
    }
    return hash_[x]==u;
}
int main(){
    scanf("%d%d%d%d", &n, &X, &Y, &Z);
    for(int i = 1; i <= n; i++) {
        X = (X+Y)%Z;
    insert(X);
    }
    scanf("%d%d%d%d", &m, &X, &Y, &Z);
    for(int i = 1; i <= m; i++) {
        X = (X+Y)%Z;
    if(query(X)) printf("%d\n",i);
    }
    return 0;
}
