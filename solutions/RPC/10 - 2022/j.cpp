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

ll l;
int side[5];

bool check(ll x, int n, int m) {
    side[0] = n, side[1] = m-1, side[2] = n-1, side[3] = m-2;
    fori(i,0,3) {
        ll r = side[i] % x;
        if(r) side[i]--, side[i+1]++;
    }
    bool ok = 1;
    ll s = 0;
    fori(i,0,4) {
        s += side[i];
        ok &= side[i] % x == 0;
    }
    return ok && l == s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        l = 2ll*n + 2ll*(m-2);
        set<int> s;
        vl d;
        for(ll i = 1; i*i <= l && i <= min(n, m); i++) {
            if(l % i == 0) {
                if(check(i, n, m) || check(i, m, n)) {
                    s.insert(i);
                }
                if(i != l/i && l/i <= min(n, m) && (check(l/i, n, m) || check(l/i, m, n))) {
                    s.insert(l/i);
                }
            }
        }
        cout << sz(s);
        for(auto i : s) {
            cout << ' ' << i;
        }
        cout << endl;
    }
    return 0; 
}