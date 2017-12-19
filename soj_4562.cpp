#include <cstdio>
#include <iostream>
using namespace std;
char haha[27] = {'0','Z','Y','X','W','V','U','T','S','R','Q','P','O','N',
    'M','L','K','J','I','H','G','F','E','D','C','B','A'};
int x;
int ans[233];
int main() {
    while(scanf("%d",&x)!=EOF) {
        int t = 0;
        if(x==0) {
            printf("0\n");
            continue;
        }
        while(x) {
            ans[++t] = x%27;
            x/=27;
        }
        for(int i = t ; i >= 1 ; --i) printf("%c",haha[ans[i]]);
        printf("\n");
    }
}
