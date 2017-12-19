#include <cstdio>
#include <iostream>
using namespace std;
char a[233];
int len;
int main() {
    while((a[len++]=getchar())!=EOF);
    for(int i = len-2 ; i >= 0 ; --i) printf("%c",a[i]);
    cout << endl;
}
