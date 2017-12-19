#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char b[233333];
char a[23];
bool flag = false;
int main() {
    for(;;) {
        int i = 0;
        while((a[i]=getchar())!='\n') i++;
        if(a[0]=='E') break;
        if(flag) printf("\n");
        else flag = true;
        i = 0;
        while((b[i]=getchar())!='\n') i++;
        int len_ = i;
        for(i = 0 ; i < len_ ; ++i) {
            char x = b[i];
            if('A'<=x && x<='Z') {
                x -= 'A';
                x = ((x+26)-5)%26+'A';
            }
            printf("%c",x);
        }
        i = 0;
        while((a[i]=getchar())!='\n') i++;
    }
}
