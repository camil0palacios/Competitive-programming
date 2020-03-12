#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int frq[101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        frq[x]++;
    }
    int ans = 0;
    for(int i = 0; i <= 100; i++){
        ans += frq[i]/2;
    }
    cout << ans << endl;
    return 0;
}