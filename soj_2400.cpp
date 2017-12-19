#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000003;
char a[N];
char b[4] = {'L','O','V','E'};
int T;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%s",a);
        int lena = strlen(a);
        bool flag = false;
        for(int i = 0 ; i < lena ; ++i) {
            bool tmp = true;
            for(int j = 0 ; j < 4 ; ++j) {
                if(i+j>=lena) {
                    tmp = false;
                    break;
                }
                if(a[i+j]!=b[j]) {
                    tmp = false;
                    break;
                }
            }
            if(tmp) {
                flag = true;
                break;
            }
        }
        if(flag) printf("LOVE\n");
        else printf("SINGLE\n");
    }
}
