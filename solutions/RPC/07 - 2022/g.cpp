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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    fore(st,0,6) {
        set<char> m;
        bool ok = 1;
        fori(i,0,n) {
            if((st + i) % 7 == 0) m.clear();
            if(m.count(s[i])) { ok = 0; break; }
            m.insert(s[i]);
        }
        if(ok) {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}