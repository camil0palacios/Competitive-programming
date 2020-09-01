#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int res = n % 2;
        n /= 2;
        if(res != 0){
            n--;
            res = 3;
        }
        if(res)cout << '7';
        cout << string(n, '1') << endl;
    }
    return 0;
}