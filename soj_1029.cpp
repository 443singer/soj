#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int q[1024*170+10];
int bianhao[1024*170+10];
int h,t;
int cheng[4] = {2,3,5,7};
long long tmp;
void Bfs() {
    q[1] = 1;
    t = 1;
    bianhao[1] = -1;
    while(h<t && t<=7000) {
        h++;
        for(int i = 0 ; i < 4 ; ++i) {
            if(bianhao[h] <= i) {
                tmp = 1ll*q[h]*cheng[i];
                if(tmp>2000000000) break;
                q[++t] = q[h]*cheng[i];
                bianhao[t] = i;
            }
        }
    }
    sort(q+1,q+1+t);
}
int main() {
    Bfs();
    int n;
    while(scanf("%d",&n),n) {
        if(n%10>=1 && n%10 <= 3 && n/10%10!=1) {
            if(n%10==1) printf("The %dst humble number is",n);
                   if(n%10==2) printf("The %dnd humble number is",n);
                   if(n%10==3) printf("The %drd humble number is",n);    
        } else {
            printf("The %dth humble number is",n);
        }
        printf(" %d.\n",q[n]);
    }
}
