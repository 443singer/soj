#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 54;
int n,m;
char a[N][N],b[N][N];
int main() {
    scanf("%d%d",&n,&m);
    getchar();
    for(int i = 0 ; i < n ; ++i) scanf("%s",a[i]);
    getchar();
    for(int i = 0 ; i < n ; ++i) scanf("%s",b[i]);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            if(a[i][j]!=b[i][j])
                printf("(%d,%d)\n",i,j);
}
