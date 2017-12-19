#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DBL;
typedef long double LDBL;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) (a*a)

const int maxn=3e5+10;
int N;
int inpt[2*maxn];

int main()
{
    int T;
    scanf("%d", &T);
    for(int ck=1; ck<=T; ck++)
    {
        scanf("%d", &N);
        for(int i=0; i<N; i++)
        {
            scanf("%d", &inpt[i]);
            inpt[i+N]=inpt[i];
        }
        int p1=0,p2=1;
        while(p1<N&&p2<N)
        {
            int len=0;
            while(inpt[p1+len]==inpt[p2+len]&&len<N) len++;
            if(len==N) break;
            if(inpt[p1+len]>inpt[p2+len]) p1+=len+1;
            else p2+=len+1;
            if(p1==p2) p2++;
        }
        int ansp=min(p1, p2);
        for(int i=ansp; i<ansp+N; i++) printf("%d ", inpt[i]);
        puts("");
    }
    return 0;
}
