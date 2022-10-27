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

bool check(ll n, ll k, ll d1, ll d2) {
    ll x1 = (k + 2*d1 + d2) / 3;
    ll x2 = x1 - d1;
    ll x3 = x2 - d2;
    if(x1+x2+x3 != k || x1 < 0 || x2 < 0 || x3 < 0) return 0;
    if(x1 <= n/3 && x2 <= n/3 && x3 <= n/3) return 1;
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        if(n%3 == 0 && (
            check(n, k, d1, d2) ||
            check(n, k, -d1, d2) ||
            check(n, k, d1, -d2) ||
            check(n, k, -d1, -d2)
        )) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0; 
}