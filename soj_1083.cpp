#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define P pair<int,int>
const int N = 203;
struct cmp {
    bool operator () (P a,P b) {
        return a.second>b.second;
    }
};
priority_queue<P,vector<P >, cmp>q;
int n,m;
int dist[N],first[N],next_[N*N*2],to[N*N*2],eg;
inline void addedge(int x,int y) {
    next_[++eg] = first[x];
    first[x] = eg;
    to[eg] = y;
}
inline void add(int x,int y) {
    addedge(x,y);
    addedge(y,x);
}
char a[N][7];
int b[N];
int mp[26*26*26*26+10];
bool vis[N];
int path_[N];
void dijkstra(int st) {
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    dist[st] = 0;
    q.push(make_pair(st,0));
    while(!q.empty()) {
        int now = q.top().first ; q.pop();
        if(vis[now]) continue;
        vis[now] = 1;
        for(int i = first[now] ; i ; i = next_[i]) {
            int newdis = dist[now] + 1;
            if(dist[to[i]] > newdis) {
                path_[to[i]] = now;
                dist[to[i]] = newdis;
                q.push(make_pair(to[i],dist[to[i]]));
            }
        }
    }
}
int q2[N],t;
void solve(int st,int ed) {
    t = 0;
    q2[++t] = ed;
    while(ed!=st) {
        ed = path_[ed];
        q2[++t] = ed;
    }
    char tmp[7];
    for(int i = t ; i >= 1 ; --i) {
        int now = b[q2[i]];
        for(int j = 3 ; j >= 0 ; --j) {
            tmp[j] = now%26+'a';
            now /= 26;
        }
        for(int j = 0 ; j < 4 ; ++j) printf("%c",tmp[j]);
        printf(" ");    
    }
    printf("\n");
}
bool pd(int i,int j) {
    int cnt = 0;
    for(int k = 0 ; k < 4 ; ++k)
        if(a[i][k]!=a[j][k]) cnt++;
    if(cnt==1) return true;
    return false;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++i) {
        scanf("%s",a[i]);
        int tmp = 1;
        for(int j = 3 ; j >= 0 ; --j) {
            b[i] += tmp*(a[i][j]-'a');
            tmp *= 26;
        }
        mp[b[i]] = i;
    }
    for(int i = 1 ; i <= n ; ++i)
        for(int j = i+1 ; j <= n ; ++j)
            if(pd(i,j)) 
                add(i,j);
    while(m--) {
        char zxr[7];
        scanf("%s",zxr);
        int st = 0;
        int tmp = 1;
        for(int i = 3 ; i >= 0 ; --i) {
            st += (zxr[i]-'a')*tmp;
            tmp*=26;
        }
        scanf("%s",zxr);
        int ed = 0;
        tmp = 1;
        for(int i = 3 ; i >= 0 ; --i) {
            ed += (zxr[i]-'a')*tmp;
            tmp*=26;
        }
        dijkstra(mp[st]);
        solve(mp[st],mp[ed]);
    }
}
