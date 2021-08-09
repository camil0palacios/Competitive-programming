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

const int Mxn = 210;
int dp[Mxn][Mxn][2];
vi a, b;
vector<pair<string, int>> res;

bool check(int i, int j, bool lst, bool nxt) {
    if(!lst) {
        if(!nxt) return a[i] <= a[i-1];
        return 2*b[j] <= a[i-1];
    } 
    if(!nxt) return 2*a[i]*a[i] <= 4*b[j-1]*b[j-1];
    return b[j] <= b[j-1];
}

bool go(int i, int j, bool lst) {
    if(i == sz(a) && j == sz(b)) return 1;
    int & ans = dp[i][j][lst]; 
    if(ans != -1) return ans;
    if(i < sz(a) && check(i, j, lst, 0) && go(i+1, j, 0)) {
        res.eb("cube", a[i]);
        return ans = 1;
    } 
    if(j < sz(b) && check(i, j, lst, 1) && go(i, j+1, 1)) {
        res.eb("cylinder", b[j]);
        return ans = 1;
    }
    return ans = 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    cin >> n;
    fori(i,0,n) {
        string s; int x;
        cin >> s >> x;
        if(s == "cube") a.eb(x);
        else b.eb(x);
    }
    a.eb(2000), b.eb(2000);
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    memset(dp, -1, sizeof dp);
    if(go(1,1,0) || go(1,1,1)) {
        for(auto & p : res) cout << p.ft << ' ' << p.sd << endl;
    } else cout << "impossible" << endl;
    return 0; 
}