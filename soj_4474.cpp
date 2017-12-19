#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-5;
double y;
double pow_(double x,int k) {
    double ans = 1;
    while(k) {
        if(k&1) ans*=x;
        x*=x;
        k>>=1;
    }
    return ans;
}
bool check(double mid) {
    double tmp = 0;
    tmp += 7*pow_(mid,6);
    tmp += 48*pow_(mid,5);
    tmp += 6*pow_(mid,1);
    tmp -= y;
    if(tmp>eps) return 1;
    return 0;
}
int main() {
    while(scanf("%lf",&y)!=EOF) {
        double l = 0,r = 100;
        while(r-l>eps) {
            double mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        double ans = 0;
        ans += pow_(l,7);
        ans += 8*pow_(l,6);
        ans += 3*pow_(l,2);
        ans -= y*l;
        printf("%.4lf\n",ans);
    }
}
