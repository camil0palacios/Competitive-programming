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

const int Mxn = 110;
string a[Mxn];

bool cmp(string & s, string & t) {
    if(sz(s) == sz(t)) return s < t;
    return sz(s) < sz(t);
}

int increase(int idx) {
    string s, t;
    s = a[idx];
    t = a[idx-1];
    int n = sz(s), m = sz(t);
    fori(i,0,n) {
        if(s[i] == t[i]) continue;
        if(s[i] > t[i]) {
            s += string(m-n, '0');
            a[idx] = s;
            return m-n;
        } else {
            s += string(m-n+1, '0');
            a[idx] = s;
            return m-n+1;
        }
    }
    bool nine = 1;
    fori(i,n,m) nine &= t[i] == '9';
    if(nine) {
        s += string(m-n+1, '0');
        a[idx] = s;
        return m-n+1;
    }
    s += string(m-n, '0');
    int acc = 1;
    forr(i,m-1,n) {
        int x = acc + (t[i]-'0');
        int r = x % 10;
        acc = x / 10;
        s[i] = char(r + '0');
    }
    a[idx] = s;
    return m-n;
}

void solve() {
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    ll ans = 0;
    fori(i,1,n) {
        if(cmp(a[i-1], a[i])) continue;
        ans += increase(i);
    }
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