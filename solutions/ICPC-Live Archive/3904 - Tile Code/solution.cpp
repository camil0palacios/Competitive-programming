#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll f[31], s[31];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);   
    f[1] = 1, f[2] = 3;
    for(int i = 3; i <= 30; i++) {
        f[i] = f[i - 1] + 2*f[i - 2];
    } 
    for(int i = 3; i <= 30; i++) {
        if(i & 1) s[i] = f[(i - 1)/2];
        else s[i] = f[i / 2] + 2*f[(i - 2)/2];
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (s[n] + f[n]) / 2 << endl;
    } 
    return 0;   
}