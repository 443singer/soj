#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        int ans = 1;
        int tmp = 1;
        while(tmp%=n) {
            ans++;
            tmp = tmp*10+1;
        }
        cout << ans << endl;
    }
}
