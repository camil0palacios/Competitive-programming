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
    int n, m;
    cin >> n >> m;
    vi gr0(m), gr1;
    fori(i,0,m) cin >> gr0[i];
    int ans = 0;
    fori(i,0,n) {
        multiset<int> s;
        fori(j,0,m) {
            int a; cin >> a;
            s.insert(a);
        }
        vi ngr0, ngr1;
        for(auto & a : gr1) {
            if(s.find(a) != s.end()) {
                s.erase(s.find(a));
                ngr1.eb(a);
            } else ans++;
        }
        for(auto & a : gr0) {
            if(s.find(a) != s.end()) {
                s.erase(s.find(a));
                ngr0.eb(a);
            }
        }
        for(auto & a : s) ngr1.eb(a);
        gr1 = ngr1;
        gr0 = ngr0;

    }
    cout << ans << endl;
}

int main() { 
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}