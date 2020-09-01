#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, n;
    while(cin >> n >> a >> b){
        cout << (n - a > b ? b + 1: n - a)<< endl;
    }
    return 0;
}