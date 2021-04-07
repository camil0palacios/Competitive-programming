#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

void solve() {
    int n; 
    string a, b;
    cin >> n >> a >> b;
    int o = 0, z = 0;
    fori(i,0,n) a[i] == '1' ? o++ : z++;
    bool ok = 1, t = 1;
    forr(i,n-1,0) {
        a[i] = t ? a[i] : char((a[i]-'0')^1 + '0');
        if(a[i] == b[i]) {
            a[i] == '1' ? o-- : z--;
            continue;
        }
        if(o != z) { ok = 0; break; }
        b[i] == '1' ? o-- : z--;
        t ^= 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}