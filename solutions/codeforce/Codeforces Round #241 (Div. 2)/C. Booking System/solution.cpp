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

struct req {
    int c, p, i;
    req(){}
    bool operator<(const req & r) { return mp(c, p) > mp(r.c, r.p); }
};

const int Mxn = 1010;
int n, k;
req a[Mxn];
ii b[Mxn];
int dp[Mxn][Mxn];
vii res;

int go(int i, int j) {
    if(i == n || j == k) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = max(go(i+1, j), go(i, j+1));
    if(a[i].c <= b[j].ft) {
        ans = max(ans, go(i+1, j+1) + a[i].p);
    }
    return dp[i][j] = ans;
}

void rec(int i, int j) {
    if(i == n || j == k) return;
    int cur = go(i, j);
    if(a[i].c <= b[j].ft && cur == go(i+1, j+1) + a[i].p) {
        res.eb(a[i].i, b[j].sd);
        rec(i+1, j+1);
    }
    else if(cur == go(i+1, j)) rec(i+1, j);
    else rec(i, j+1);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fori(i,0,n) cin >> a[i].c >> a[i].p, a[i].i = i;
    cin >> k;
    fori(i,0,k) cin >> b[i].ft, b[i].sd = i;
    sort(a, a+n);
    sort(b, b+k, greater<ii>());
    memset(dp, -1, sizeof dp);
    rec(0,0);
    cout << res.size() << ' ' << go(0,0) << endl;
    for(auto & p : res) 
        cout << p.ft+1 << ' ' << p.sd+1 << endl;
    return 0;
}