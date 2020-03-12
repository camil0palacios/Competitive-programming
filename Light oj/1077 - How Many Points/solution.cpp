#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve(){
    long long x[2], y[2];
    for(int i = 0; i < 2; i++)cin >> x[i] >> y[i];
    long long a = abs(x[1] - x[0]);
    long long b = abs(y[1] - y[0]);
    if(a < b)swap(a, b);
    cout << __gcd(a, b) + 1 << endl;
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}