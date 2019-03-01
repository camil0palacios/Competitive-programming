#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int pos = 0, neg = 0, tmp;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            pos += (tmp > 0);
            neg += (tmp < 0);
        }
        if(pos == neg && pos >= ceil(n/2.0))cout << 1 << endl;
        else if(pos >= ceil(n/2.0))cout << 1 << endl;
        else if(neg >= ceil(n/2.0))cout << -1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}