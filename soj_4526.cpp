#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define P pair<int,int>
const int N = 1003;
const int M = 100003;
const int INF = 2000000003;
int first[N],next_[M],to[M],dis[M],eg;
inline void addedge(int x,int y,int d) {
    next_[++eg] = first[x];
    first[x] = eg;
    to[eg] = y;
    dis[eg] = d;
}
struct cmp {
    bool operator() (P a,P b) {
        return a.second>b.second;
    }
};
priority_queue<P,vector<P >,cmp>q;
int n,m;
int dist[N];
int S,T;
bool vis[N];
void dijkstra() {
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    dist[S] = 0;
    q.push(make_pair(S,0));
    while(!q.empty()) {
        int u = q.top().first;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = first[u] ; i ; i = next_[i]) {
            int v = to[i];
            int newdis = dist[u] + dis[i];
            if(newdis < dist[v]) {
                dist[v] = newdis;
                q.push(make_pair(v,dist[v]));
            }
        }
    }
}
int first2[N],next2[M*2],to2[M*2],cap[M*2],eg2;
inline void addedge2(int x,int y,int f) {
    next2[++eg2] = first2[x];
    first2[x] = eg2;
    to2[eg2] = y;
    cap[eg2] = f;
}
inline void add(int x,int y,int f) {
    addedge2(x,y,f);
    addedge2(y,x,0);
}
void prepare() {
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = first[i] ; j ; j = next_[j]) {
            int v = to[j];
            if(dist[i]+dis[j]==dist[v]) {
                add(i,v,1);
            }
        }
    }
}    
int cur[N],dep[N],bfs[N];
bool Bfs() {
    memset(dep,0,sizeof(dep));
    dep[S] = 1;
    int h = 0 , t = 1;
    bfs[1] = S;
    while(h<t) {
        int u = bfs[++h];
        for(int i = first2[u] ; i ; i = next2[i]) {
            int v = to2[i];
            if(cap[i] && !dep[v]) {
                dep[v] = dep[u] + 1;
                bfs[++t] = v;
            }
        }
    }
    return dep[T];
}
int dfs(int u,int flow) {
    if(u==T || !flow) return flow;
    int &i = cur[u],ret = 0;
    if(i==-1) i = first2[u];
    for(; i ; i = next2[i]) {
        int v = to2[i];
        if(cap[i] && dep[v] == dep[u]+1) {
            int t = dfs(v,min(flow,cap[i]));
            cap[i] -= t ; cap[i^1] += t;
            ret += t ; flow -= t;
        }
        if(!flow) return ret;
    }
    return ret;
}
int dinic() {
    int ret = 0;
    while(Bfs()) {
        memset(cur,-1,sizeof(cur));
        ret += dfs(S,INF);
    }
    return ret;
}
int main() {
    int cnt;
    scanf("%d",&cnt);
    while(cnt--) {
        memset(first,0,sizeof(first));
        memset(first2,0,sizeof(first2));
        eg = 0;
        eg2 = 1;
        scanf("%d%d",&n,&m);
        for(int i = 1 ; i <= m ; ++i) {
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            addedge(x,y,d);
        }
        scanf("%d%d",&S,&T);
        dijkstra();
        prepare();
        printf("%d\n",dinic());
    }
}
