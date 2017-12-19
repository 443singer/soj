#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
const double eps = 1e-5;
int main() {
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF) {
        int ans = 0;
        double nowans = a*1.0/(c*1.0)+b*1.0/(d*1.0);
        double tmpans = c*1.0/(d*1.0)+a*1.0/(b*1.0);
        if(tmpans-nowans>eps) {
            nowans = tmpans;
            ans = 1;
        }
        tmpans = d*1.0/(b*1.0)+(c*1.0)/(a*1.0);
        if(tmpans-nowans>eps) {
            nowans = tmpans;
            ans = 2;
        }
        tmpans = (b*1.0)/(a*1.0)+(d*1.0)/(c*1.0);
        if(tmpans-nowans>eps) {
            nowans = tmpans;
            ans = 3;
        }
        printf("%d\n",ans);
    }
}
