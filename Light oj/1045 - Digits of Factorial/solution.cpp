#include <bits/stdc++.h>
using namespace std;

double logg[1000007];

void init(){
    for(int i = 1; i < 1000007; i++){
        logg[i] = logg[i-1] + log(i);
    }
}

void solve(){
    int n, b;
    cin >> n >> b;
    long long cnt = logg[n]/log(b) + 1;
    cout << cnt << endl;
}

int main(){
    init();
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}