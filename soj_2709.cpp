#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 53;
int T;
char a[233333];
int b[N];
int main() {
    scanf("%d",&T);
    getchar();
    while(T--) {
        int len = 0;
        int cnt = 0;
        while((a[len++]=getchar())!='\n');len--;
        for(int i = 0 ; i < len ; ++i) {
            if(a[i]==' ') continue;
            int tmp = a[i]-'0';
            while(a[i+1]!=' ' && i<len-1) {
                i++;
                tmp*=10;
                tmp += a[i]-'0';
            }
            b[++cnt] = tmp;
        }
        sort(b+1,b+1+cnt);
        for(int i = 1 ; i <= cnt ; ++i) printf("%d ",b[i]);
        printf("\n");
    }
}
