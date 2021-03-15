#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int n, q;
set<ll> s;

void rec(vi & a) {
    int n = sz(a);
    ll sum = 0; int mn = 1e9, mx = 0;
    bool eq = 1;
    fori(i,0,n) {
        sum += a[i];
        mn = min(mn, a[i]), mx = max(mx, a[i]);
        if(i) eq &= a[i] == a[i-1];
    }
    s.insert(sum);
    if(eq) return;
    int mid = (mx + mn) >> 1;
    vi left, right;
    fori(i,0,n) {
        if(a[i] <= mid) left.eb(a[i]);
        else right.eb(a[i]);
    }
    rec(left);
    rec(right);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        vi a(n);
        fori(i,0,n) cin >> a[i];
        s.clear();
        rec(a);
        fori(i,0,q) {
            int x;
            cin >> x;
            cout << (s.count(x) ? "Yes" : "No") << endl;
        }
    }
    return 0; 
}