#include <bits/stdc++.h>
using namespace std;

long long pos(long long n){
    return n/2;
}

long long neg(long long n){
    return pos(n - 1) - n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, l, r;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> l >> r;
            if(l == r){
                cout << (r % 2 ? -r : r) << endl;
                continue;
            }
            r = (r % 2 ? neg(r) : pos(r));
            l = ((l - 1) % 2 ? neg(l-1) : pos(l-1));
            cout << r - l << endl;
        }
    }
    return 0;
}