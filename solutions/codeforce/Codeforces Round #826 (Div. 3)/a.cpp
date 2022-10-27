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
    string s, t;
    cin >> s >> t;
    if(s == t) cout << "=" << endl;
    else {
        if(t == "M") {
            cout << (s.back() == 'S' ? "<" : ">") << endl;
        }
        else if(s == "M") {
            cout << (t.back() == 'S' ? ">" : "<") << endl;
        }
        else if(s.back() == t.back()) {
            if(s.back() == 'S') cout << (sz(s) < sz(t) ? ">" : "<") << endl;
            else cout << (sz(s) < sz(t) ? "<" : ">") << endl;
        } else {
            cout << (s.back() == 'S' ? "<" : ">") << endl;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}