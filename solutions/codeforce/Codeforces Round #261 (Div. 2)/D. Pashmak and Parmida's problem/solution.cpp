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

const int Mxn = 1e6 + 5;

struct ft {
    int n;
    vi bit;
    ft(int n): n(n) { bit.resize(n); }
    void upd(int i, int val) {
        for(; i < n; i += i&-i) bit[i] += val;
    }
    int sum(int i) {
        int ans = 0;
        for(; i; i -= i&-i) ans += bit[i];
        return ans;
    }
    int qry(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

int a[Mxn], t[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    ft bit(Mxn);
    map<int,int> cnt, lst;
    forr(i,n-1,0) {
        t[i] = ++cnt[a[i]];
        bit.upd(t[i], 1);
    }
    ll ans = 0;
    fori(i,0,n) {
        int x = ++lst[a[i]];
        bit.upd(t[i], -1);
        if(x) ans += bit.qry(1, x-1);
    }
    cout << ans << endl;
    return 0; 
}