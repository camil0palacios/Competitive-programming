#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q; 
    long long k,x;
    cin >> q;
    while(q--){
        cin >> k >> x;
        cout << ((9*k)-9)+x << endl;
    }
    return 0;
}