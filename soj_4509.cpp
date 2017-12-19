#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5+10;
const long long INF = 1100000000000000000;
int n,T,x[N],w,q[N],h,t;
long long dp[N],X[N],Y[N];
inline bool pd1(int j,int k,int i) {
    if((X[k]-X[j])*x[i] > Y[k] - Y[j]) return true;
    return false;
}
inline bool pd2(int j,int k,int i) {
    long long x1 = X[i] - X[k];
    long long y1 = Y[i] - Y[k];
    long long x2 = X[k] - X[j];
    long long y2 = Y[k] - Y[j];
    if(x1*y2-x2*y1>0) return true;
    return false;
}
long long min(long long a,long long b) {return a<b?a:b;}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&w);
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&x[i]);
        h = 1 ; t = 1;
        q[1] = 1;
        dp[1] = w;
        X[1] = 2*x[1];
        Y[1] = 1ll*x[1]*x[1];
        for(int i = 2 ; i <= n ; ++i) {
            dp[i] = INF; 
            while(h<t && pd1(q[h],q[h+1],i)) h++;
            int j = q[h];
            dp[i] = dp[j-1]+1ll*(x[i]-x[j])*(x[i]-x[j])+w;
            dp[i] = min(dp[i],dp[i-1]+w);
            X[i] = 2*x[i];
            Y[i] = dp[i-1]+1ll*x[i]*x[i];
            while(h<t && pd2(q[t-1],q[t],i)) t--;
            q[++t] = i;
        }
        cout << dp[n] << endl;
    }
}
