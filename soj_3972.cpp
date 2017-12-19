#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int tmp[13];
int get_m(int x) {
    int t = 0;
    while(x) {
        tmp[++t] = x%10;
        x/=10;
        if(tmp[t]==6) tmp[t] = 5;
    }
    int tmp2 = 0;
    for(int i = t ; i >= 1 ; --i) {
            tmp2 *= 10;
        tmp2 += tmp[i];
    }
    return tmp2;
}    
int get_max(int x) {
    int t = 0;
    while(x) {
        tmp[++t] = x%10;
        x/=10;
        if(tmp[t]==5) tmp[t] = 6;
    }
    int tmp2 = 0;
    for(int i = t ; i >= 1 ; --i) {
            tmp2 *= 10;
        tmp2 += tmp[i];
    }
    return tmp2;
}
int main() {
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF) {
        int mina = get_m(a);
        int minb = get_m(b);
        printf("%d ",mina+minb);
        int maxa = get_max(a);
        int maxb = get_max(b);
        printf("%d\n",maxa+maxb);
    }
}
