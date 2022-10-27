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

const int Mxn = 110;
int n;
ll a[Mxn];

bool check(int g) {
    bool ok = 1;
    ll l = -1;
    fori(i,0,n) {
        ok &= l != (a[i] % g);
        l = a[i] % g;
    }
    return ok;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,n) cin >> a[i];
        ll g1 = 0, g2 = 0;
        fori(i,0,n) {
            if(i & 1) g1 = __gcd(g1, a[i]);
            else g2 = __gcd(g2, a[i]);
        }
        if(check(g1)) cout << g1 << endl;
        else if(check(g2)) cout << g2 << endl;
        else cout << 0 << endl;        
    }
    return 0; 
}