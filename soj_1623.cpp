#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char a[233];
int len;
int main() {
while(scanf("%s",a)==1) {
len = strlen(a);
for(int i = 0 ; i < len ; ++i) {
if(a[i]>='a' && a[i]<='z') a[i] = a[i]-'a'+'A';
printf("%c",a[i]);
}
printf("\n");
}
}
