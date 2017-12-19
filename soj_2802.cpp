#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5+12;
struct hp {
    int x,v;
}X[N],Y[N];
long long ans[N];
bool cmp(hp a,hp b) {return a.x<b.x;}
int n;
int main() {
    while(scanf("%d",&n)!=EOF) {
        memset(ans,0,sizeof(ans));
        int x,y;
        for(int i = 1 ; i <= n ; ++i) {
            scanf("%d%d",&x,&y);
            X[i].x = x ; X[i].v = i;
            Y[i].x = y ; Y[i].v = i;
        }
        sort(X+1,X+1+n,cmp);
        sort(Y+1,Y+1+n,cmp);
        long long nowans = 0;
        for(int i = 2 ; i <= n ; ++i) nowans += abs(X[i].x-X[1].x);
        ans[X[1].v] += nowans;
        for(int i = 2 ; i <= n ; ++i) {
            nowans += (i-1)*(X[i].x-X[i-1].x);
            nowans -= (n-i+1)*(X[i].x-X[i-1].x);
            ans[X[i].v] += nowans;    
        }
        nowans = 0;
        for(int i = 2 ; i <= n ; ++i) nowans += abs(Y[i].x-Y[1].x);
        ans[Y[1].v] += nowans;
        for(int i = 2 ; i <= n ; ++i) {
            nowans += (i-1)*(Y[i].x-Y[i-1].x);
            nowans -= (n-i+1)*(Y[i].x-Y[i-1].x);
            ans[Y[i].v] += nowans;    
        }
        long long tmpans = 100000;
        tmpans = tmpans*tmpans*2;
        for(int i = 1 ; i <= n ; ++i) tmpans = min(tmpans,ans[i]);
        cout << tmpans << endl;
    }
}
