#include <cstdio>
#include <iostream>
using namespace std;
int n,k,ans;
void dfs(int butt,int k) {
    if(butt < k) return;
    ans += butt/k;
    dfs(butt%k+butt/k,k);
}
int anss[2003];
int main() {
    for(int i = 1 ; i <= 1000 ; ++i) {
        ans = i;
        n = i;
        k = 5;
        dfs(n,k);
        anss[ans] = i;
    }
    for(int i = 2000 ; i >= 1 ; --i) {
        if(anss[i]==0) anss[i] = anss[i+1];
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        cout << anss[n] << endl;
    }
}    
