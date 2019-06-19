#include <bits/stdc++.h>
using namespace std;

void solve(){
    int tr[3];
    cin >> tr[0] >> tr[1] >> tr[2];
    bool ans = 0;
    for(int i = 0; i < 3; i++){
        int a = tr[(i+1)%3], b = tr[(i+2)%3], c = tr[i]; 
        if(a*a + b*b == c*c){
            ans = 1;
            break;
        }
    }
    cout << (ans ? "yes" : "no") << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}