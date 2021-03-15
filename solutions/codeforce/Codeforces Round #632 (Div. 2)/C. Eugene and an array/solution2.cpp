#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    map<ll,int> m;
    ll ans = 0, s = 0;
    int l = 0;
    m[0] = 0;
    fori(i, 1, n + 1) {
        int x; cin >> x;
        s += x;
        if(m.count(s)) {
            l = max(l, m[s] + 1);
        }
        ans += i - l;
        m[s] = i;
    }
    cout << ans << endl;
    return 0; 
}