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

struct Bit {
    vi bit;
    Bit(int n) { bit.resize(n+5); }
    int get(int i) { return i & -i; }
    void add(int i, int x) {
        for(; i < sz(bit); i += get(i)) bit[i] += x;
    }
    int sum(int i) {
        int ans = 0;
        for(; i > 0; i -= get(i)) ans += bit[i];
        return ans;
    }
    int query(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

const int Mxn = 2e5 + 5;
ii r[Mxn];
int ans[Mxn][2];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    // map points
    vi to;
    fore(i,1,n) {
        cin >> r[i].ft >> r[i].sd;
        to.eb(r[i].ft);
        to.eb(r[i].sd);
    }
    map<int,int> m;
    int cnt = 0;
    sort(all(to));
    fori(i,0,sz(to)) {
        if(m.count(to[i])) continue;
        m[to[i]] = ++cnt;
    }
    vii p;
    fore(i,1,n) {
        r[i].ft = m[r[i].ft];
        r[i].sd = m[r[i].sd];
        p.eb(r[i].ft, -i);
        p.eb(r[i].sd, i);
    }
    // algorithm
    sort(all(p), [&](ii a, ii b) {
        if(a.ft == b.ft) {
            if(a.sd > 0 && b.sd > 0) return r[a.sd].ft > r[b.sd].ft;
            return a.sd < b.sd;
        }
        return a.ft < b.ft;
    });
    Bit op(cnt), cl(cnt);
    for(auto & pt : p) {
        int x = pt.ft, i = pt.sd;
        if(i < 0) op.add(x, 1);
        else {
            op.add(r[i].ft, -1);
            ans[i][0] = cl.query(r[i].ft, r[i].sd);
            ans[i][1] = op.query(1, r[i].ft);
            cl.add(r[i].ft, 1);
        }
    }
    fore(i,1,n) {
        if(i != 1) cout << ' ';
        cout << ans[i][0];
    } 
    cout << endl;
    fore(i,1,n) {
        if(i != 1) cout << ' ';
        cout << ans[i][1];
    } 
    cout << endl;
    return 0; 
}