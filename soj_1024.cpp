#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
char a[233];
map<string,int>zxr;
string ed = "vwxyz";
string get_next(string x) {
    int len = x.size();
    for(int i = len-1 ; i >= 0 ; --i) {
        if(i==len-1) {
            if(x[i]!='z') {
                x[i]++;
                return x;
            }
        } else if(x[i]+1<x[i+1]) {
            x[i]++;
            for(int j = i+1 ; j <=len-1 ; ++j) x[j] = x[j-1]+1;
            return x;
        }
    }
    x.resize(x.size()+1,'a');
    x[0] = 'a';
    len = x.size();
    for(int i = 1 ; i < len ; ++i) {
        x[i] = x[i-1]+1;
    }
    return x;
}
int main() {
    int cnt = 0;
    string st = "a";
    zxr[st] = ++cnt;
    do {
        st = get_next(st);
        zxr[st] = ++cnt;    
    } while(st!=ed);
    while(scanf("%s",a)!=EOF) {
        int len = strlen(a);
        if(len>5) {
            printf("0\n");
            continue;
        }
        bool flag = true;
        for(int i = 1 ; i < len ; ++i) {
            if(a[i]<=a[i-1]) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            printf("0\n");
            continue;
        }
        string tmp = string(a);
        cout << zxr[tmp] << endl;
    }
}
