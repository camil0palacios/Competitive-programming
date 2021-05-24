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

const int Mxn = 2e5 + 5;
int a[Mxn];

struct ft {
    int n;
    vi bit;
    ft(int n): n(n) { bit.resize(n); }
    void upd(int i, int v) {
        for(; i < n; i += i & -i) bit[i] += v;
    }
    int sum(int i) {
        int ans = 0;
        for(; i; i -= i & -i) ans += bit[i];
        return ans;
    }
    int qry(int l, int r) { return sum(r) - sum(l-1); }
};

struct Query { 
    int l, r, i; 
    bool operator<(const Query & qq) {
        return r < qq.r;
    }
};

Query q[Mxn];
int ans[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fore(i,1,n) cin >> a[i];
    fore(i,1,m) cin >> q[i].l >> q[i].r, q[i].i = i;
    sort(q+1, q+m+1);
    ft bit(n+2);
    map<int,int> lst;
    int j = 1;
    fore(i,1,n) {
        if(lst.count(a[i])) bit.upd(lst[a[i]], -1);
        lst[a[i]] = i;
        bit.upd(i, 1);
        while(j <= m && q[j].r == i) {
            ans[q[j].i] = bit.qry(q[j].l, q[j].r);
            j++;
        }
    }
    fore(i,1,m) cout << ans[i] << endl;
    return 0;
}