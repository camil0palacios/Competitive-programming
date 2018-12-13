#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int x; cin >> x;
        x = (((((x*567)/9)+7492)*235)/47)-498;
        if(x < 0)x*=-1;
        cout << (x%100)/10 << endl;
    }
    return 0;
}