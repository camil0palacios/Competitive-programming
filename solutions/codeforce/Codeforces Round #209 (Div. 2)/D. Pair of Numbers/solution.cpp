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

const int Mxn = 3e5 + 5;
const int Lg = 19;
int g[Mxn][Lg], m[Mxn][Lg];
int lg[Mxn];
int n, a[Mxn];

void cal() {
    lg[1] = 0;
    fori(i,2,Mxn) lg[i] = lg[i/2] + 1;
    fori(i,0,n) g[i][0] = m[i][0] = a[i];
    for(int j = 1; j <= Lg; j++) {
        for(int i = 0; i+(1 << j) <= n; i++) {
            g[i][j] = __gcd(g[i][j-1], g[i+(1 << (j-1))][j-1]);
            m[i][j] = min(m[i][j-1], m[i+(1 << (j-1))][j-1]);
        }
    }
}

ii query(int l, int r) {
    int j = lg[r-l+1];
    return mp(__gcd(g[l][j], g[r-(1 << j)+1][j]), min(m[l][j], m[r-(1 << j)+1][j]));
}

bool check(int x) {
    for(int i = 0; i+x <= n; i++) {
        auto q = query(i, i+x-1);
        if(q.ft == q.sd) return 1;
    }
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fori(i,0,n) cin >> a[i];
    cal();
    int l = 1, r = n+1, x;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) x = mid, l = mid+1;
        else r = mid-1;
    }
    vi ans;
    for(int i = 0; i+x <= n; i++) {
        auto q = query(i, i+x-1);
        if(q.ft == q.sd) {
            ans.eb(i);
        }
    }
    cout << sz(ans) << ' ' << x-1 << endl;
    for(auto & i : ans) cout << i+1 << ' ';
    cout << endl;
    return 0;
}