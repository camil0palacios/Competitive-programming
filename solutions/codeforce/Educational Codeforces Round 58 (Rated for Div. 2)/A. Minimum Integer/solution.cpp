#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        long long l, r, d;
        cin >> l >> r >> d;
        if(d < l)cout << d << endl;
        else cout << ((r/d)+1)*d << endl;
    }
    return 0;
}