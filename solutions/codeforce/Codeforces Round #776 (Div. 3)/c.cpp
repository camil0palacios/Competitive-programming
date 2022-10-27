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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<ar<int,3>> a;
        fori(i,0,m) {
            int x, w;
            cin >> x >> w;
            a.push_back({w, x, i+1});
        }
        sort(all(a));
        set<ii> s;
        ll ans = 0;
        fori(i,0,2*n) {
            ans += a[i][0];
            s.insert({a[i][1], a[i][2]});
        }
        cout << ans << endl;
        while(!s.empty()) {
            cout << (*s.begin()).sd << ' ' << (*s.rbegin()).sd << endl;
            s.erase(--s.end());
            s.erase(s.begin());
        }
    }
    return 0; 
}