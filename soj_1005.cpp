#include <cstdio>
#include <iostream>
using namespace std;
int T;
int n,a[1000003];
int main() {
    cin >> T;
    while(T--) {
        scanf("%d",&n);
        int sum = 0;
        for(int i = 1 ; i <= n ; ++i) {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        sum /= n;
        int cnt = 0;
        for(int i = 1 ; i <= n ; ++i) a[i] -= sum;
        for(int i = 1 ; i < n ; ++i)
            if(a[i]!=0) {
                a[i+1] += a[i];
                cnt++;
            }
        printf("%d",cnt);
        if(T!=0) printf("\n");
    }
}
