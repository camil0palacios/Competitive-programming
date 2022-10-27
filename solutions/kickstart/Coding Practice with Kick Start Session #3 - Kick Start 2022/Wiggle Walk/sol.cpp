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

const int N = 5e4 + 5;

set<ii> row[N], col[N];

void add(set<ii> & s, int i) {
    auto it = s.lower_bound({i, 0});
    auto left = it;
    int l = i, r = i;
    if(left != s.begin() && (--left)->sd == i-1) {
        l = left->ft;
        s.erase(left);
    }
    if(it != s.end() && it->ft == i+1) {
        r = it->sd;
        s.erase(it);
    }
    s.insert({l, r});
}

int qry(set<ii> & s, int i, bool d) {
    auto it = s.lower_bound({i, 0});
    if(it == s.end() || it->ft != i) it--;
    return d ? it->sd : it->ft;
}

void solve() {
    int n, r, c, x, y;
    string s;
    cin >> n >> r >> c >> x >> y;
    cin >> s;
    fore(i,0,c) row[i].clear();
    fore(i,0,r) col[i].clear();
    fori(i,0,n) {
        add(row[x], y), add(col[y], x);
        if(s[i] == 'N') x = qry(col[y], x, 0) - 1; 
        if(s[i] == 'S') x = qry(col[y], x, 1) + 1;
        if(s[i] == 'W') y = qry(row[x], y, 0) - 1;
        if(s[i] == 'E') y = qry(row[x], y, 1) + 1;
    }
    cout << x << ' ' << y << endl;
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