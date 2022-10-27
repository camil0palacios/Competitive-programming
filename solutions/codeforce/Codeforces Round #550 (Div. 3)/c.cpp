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
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    sort(a, a+n);
    vi inc, dec;
    inc.eb(a[0]);
    fori(i,1,n) {
        if(inc.back() < a[i]) inc.eb(a[i]);
        else dec.eb(a[i]);
    }
    sort(all(dec), greater<int>());
    fori(i,1,sz(dec)) {
        if(dec[i-1] == dec[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << sz(inc) << endl;
    for(auto & i : inc) cout << i << ' ';
    cout << endl;
    cout << sz(dec) << endl;
    for(auto & i : dec) cout << i << ' ';
    cout << endl;
    return 0; 
}