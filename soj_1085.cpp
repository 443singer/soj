#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
long long x1,y1_,z1,r1;
long long x2,y2,z2,r2;
long long x,y,z;
int n;
int main() {
    scanf("%d",&n);
    while(n--) {
        cin >> x1 >> y1_ >> z1 >> r1;
        cin >> x2 >> y2 >> z2 >> r2;
        cin >> x >> y >> z;
        long long a = 2*(x2-x1),b = 2*(y2-y1_),c = 2*(z2-z1);
        long long k = r1*r1-r2*r2+x2*x2-x1*x1+y2*y2-y1_*y1_+z2*z2-z1*z1;
        long long tmpz = k - a*x-b*y;
        if(tmpz==c*z) printf("No\n");
        else printf("Yes\n");
    }
}
