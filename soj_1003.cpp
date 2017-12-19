#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1003;
char a[N],b[N],c[2*N],d[N];
int main() {
    while(scanf("%s%s",a,b)!=EOF) {
        memset(c,0,sizeof(c));
        int lena = strlen(a);
        int lenb = strlen(b);
        for(int i = 0 ; i < lena ; ++i) d[i] = a[lena-i-1]-'0';
        for(int i = 0 ; i < lena ; ++i) a[i] = d[i];
        for(int i = 0 ; i < lenb ; ++i) d[i] = b[lenb-i-1]-'0';
        for(int i = 0 ; i < lenb ; ++i) b[i] = d[i];
        for(int i = 0 ; i < lena ; ++i)
            for(int j = 0 ; j < lenb ; ++j) {
                int now = i+j;
                c[now] += a[i]*b[j];
                c[now+1] += c[now]/10;
                c[now] %= 10;
            }
        for(int i = 0 ; i < 1200 ; ++i) {
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
        int lenc = 0;
        for(int i = 1200 ; i >= 0 ; --i) {
            if(c[i]) {
                lenc = i;
                break;
            }
        }
        for(int i = lenc ; i >= 0 ; --i) printf("%c",c[i]+'0');
        printf("\n");
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
}
