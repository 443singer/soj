#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int gcd_(int x,int y) {return y==0?x:gcd_(y,x%y);}
int n,a[10003];
int main() {
    while(scanf("%d",&n),n) {
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]);
        int cnt = 0;
        for(int i = 1 ; i <= n ; ++i) {
            for(int j = i + 1 ; j <= n ; ++j) {
                if(gcd_(a[i],a[j])==1) cnt++;
            }
        }
        if(!cnt) printf("No estimate for this data set.\n");
        else printf("%.6lf\n",sqrt(3.0*n*(n-1)/(1.0*cnt)));
    }        
}    
