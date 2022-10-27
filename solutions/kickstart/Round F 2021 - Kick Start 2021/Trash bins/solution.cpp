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

const int Mxn = 5e5 + 5;
int mn[Mxn];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int lst = -1e9;
    fori(i,0,n) mn[i] = 1e9;
    fori(i,0,n) {
        if(s[i] == '1') lst = i;
        mn[i] = min(mn[i], i - lst);
    }
    lst = 1e9;
    forr(i,n-1,0) {
        if(s[i] == '1') lst = i;
        mn[i] = min(mn[i], lst - i);
    }
    ll ans = 0;
    fori(i,0,n) ans += mn[i];
    cout << ans << endl; 
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}