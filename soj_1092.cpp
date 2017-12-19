#include <cstdio>
#include <iostream>
using namespace std;
long long a,b,x,y;
void gcd_(long long a,long long b)  {
    if(b==0) {
        x = 1;
        y = 0;
        return;
    }
    gcd_(b,a%b);
    int t = x;
    x = y;
    y = t-a/b*y;
}
int main() {
    while(cin>>a>>b) {
        if(a==0) break;
        gcd_(a,b);
        while(x-b>0) x -= b;
        while(x<0) x += b;
        cout << x << endl;
    }    
}
