#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int T,a,b,c,d;
int ans,cnt;
int dp1[33][2][2][2][2];
bool check1(int dep,int f1) {
    if(!f1) {
        int tmp = (1<<dep)&a;
        if(tmp) return 0;
    }
    return 1;
}
bool check2(int dep,int f2) {
    if(!f2) {
        int tmp = (1<<dep)&b;
        if(!tmp) return 0;
    }
    return 1;
}
bool check3(int dep,int f3) {
    if(!f3) {
        int tmp = (1<<dep)&c;
        if(tmp) return 0;
    }
    return 1;
}
bool check4(int dep,int f4) {
    if(!f4) {
        int tmp = (1<<dep)&d;
        if(!tmp) return 0;
    }
    return 1;
}
int dfs1(int dep,int f1,int f2,int f3,int f4) {
    if(dep==-1) return 0;
    if(dp1[dep][f1][f2][f3][f4]) return dp1[dep][f1][f2][f3][f4];
    int tmp_ans = 0;
    if(check2(dep,f2) && check3(dep,f3)) {
        bool t1 = ((1<<dep)&a)==0?1:f1;
        bool t4 = ((1<<dep)&d)>0?1:f4;
        tmp_ans = max(tmp_ans,dfs1(dep-1,t1,f2,f3,t4)+(1<<dep));
    }
    if(check1(dep,f1) && check4(dep,f4)) {
        bool t2 = ((1<<dep)&b)>0?1:f2;
        bool t3 = ((1<<dep)&c)==0?1:f3;
        tmp_ans = max(tmp_ans,dfs1(dep-1,f1,t2,t3,f4)+(1<<dep));
    }
    if(check1(dep,f1) && check3(dep,f3)) {
        bool t2 = ((1<<dep)&b)>0?1:f2;
        bool t4 = ((1<<dep)&d)>0?1:f4;
        tmp_ans = max(tmp_ans,dfs1(dep-1,f1,t2,f3,t4));
    }
    if(check2(dep,f2) && check4(dep,f4)) {
        bool t1 = ((1<<dep)&a)==0?1:f1;
        bool t3 = ((1<<dep)&c)==0?1:f3;
        tmp_ans = max(tmp_ans,dfs1(dep-1,t1,f2,t3,f4));
    }
    dp1[dep][f1][f2][f3][f4] = tmp_ans;
    return tmp_ans;
}
int dp2[33][2][2][2][2];
int dfs2(int dep,int tmp,int f1,int f2,int f3,int f4) {
    if(tmp+((1<<(dep+1))-1)<ans) return 0;
    if(dep==-1) return 1;
    if(dp2[dep][f1][f2][f3][f4]) return dp2[dep][f1][f2][f3][f4];
    int tmp_cnt = 0;
    if(check2(dep,f2) && check3(dep,f3)) {
        bool t1 = ((1<<dep)&a)==0?1:f1;
        bool t4 = ((1<<dep)&d)>0?1:f4;
        tmp_cnt += dfs2(dep-1,tmp+(1<<dep),t1,f2,f3,t4);
    }
    if(check1(dep,f1) && check4(dep,f4)) {
        bool t2 = ((1<<dep)&b)>0?1:f2;
        bool t3 = ((1<<dep)&c)==0?1:f3;
        tmp_cnt += dfs2(dep-1,tmp+(1<<dep),f1,t2,t3,f4);
    }
    if(check1(dep,f1) && check3(dep,f3)) {
        bool t2 = ((1<<dep)&b)>0?1:f2;
        bool t4 = ((1<<dep)&d)>0?1:f4;
        tmp_cnt += dfs2(dep-1,tmp,f1,t2,f3,t4);
    }
    if(check2(dep,f2) && check4(dep,f4)) {
        bool t1 = ((1<<dep)&a)==0?1:f1;
        bool t3 = ((1<<dep)&c)==0?1:f3;
        tmp_cnt += dfs2(dep-1,tmp,t1,f2,t3,f4);
    }
    dp2[dep][f1][f2][f3][f4] = tmp_cnt;
    return tmp_cnt;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        scanf("%d%d",&a,&b);
        scanf("%d%d",&c,&d);
        ans = cnt = 0;
        ans = dfs1(30,0,0,0,0);
        cnt = dfs2(30,0,0,0,0,0);
        printf("%d %d\n",ans,cnt);
    }
}
