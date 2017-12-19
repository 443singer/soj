#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long x;
char b[23];
long long reverse(long long a) {
    int len = 0;
    while(a) {
        b[++len] = a%10;
        a/=10;
    }
    long long tmp = 0;
    for(int i = 1 ; i <= len ; ++i) {
        tmp *= 10;
        tmp += b[i];
    }
    return tmp;
}
int main() {
    while(cin>>x) {
        long long tmp;
        int cnt = 0;
        while((tmp=reverse(x))!=x) cnt++,x += reverse(x);
        cout << cnt << " " << x << endl;
    }
}
