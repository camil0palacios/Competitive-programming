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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int lcm(int a, int b) { return a / __gcd(a, b) * b; }

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        string s, t;
        cin >> s >> t;
        if(sz(s) > sz(t)) swap(s, t);
        int n = sz(s), m = sz(t);
        int g = __gcd(m, n);
        string x = s.substr(0, g);
        bool ok = 1;
        for(int i = 0; i < n; i += g) {
            ok &= x == s.substr(i, g);
        }
        for(int i = 0; i < m; i += g) {
            ok &= x == t.substr(i, g);
        }
        if(ok) {
            int l = lcm(m, n);
            fori(i,0,l/g) cout << x;
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0; 
}