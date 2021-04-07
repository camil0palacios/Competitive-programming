#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    map<ll,int> m;
    ll ans = 0, s = 0;
    int j = -1;
    m[0] = -1;
    fori(i,0,n) {
        int a; cin >> a;
        s += a;
        if(m.count(s)) j = max(j, m[s] + 1);
        ans += (i - j);
        m[s] = i;
    }
    cout << ans << endl;
    return 0; 
}