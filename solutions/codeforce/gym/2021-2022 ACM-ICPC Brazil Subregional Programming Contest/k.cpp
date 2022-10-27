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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, d, m;
    cin >> t >> d >> m;
    vi y;
    y.eb(0);
    fori(i,0,m) {
        int x; cin >> x;
        y.eb(x);
    }
    y.eb(d);
    sort(all(y));
    bool ok = 0;
    fori(i,1,sz(y)) {
        if(y[i-1]+t <= y[i]) ok = 1;
    }
    cout << (ok ? 'Y' : 'N') << endl;
    return 0; 
}