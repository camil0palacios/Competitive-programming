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

struct FenwickTree {
    int n;
    vi f;
    FenwickTree(int n): n(n) { f.assign(n+1, 0); }
    void add(int i, int x) { for(; i <= n; i += i & -i) f[i] += x; }
    int sum(int i) {
        int ans = 0;
        for(; i; i -= i & -i) ans += f[i];
        return ans;
    }
    int qry(int l, int r) {
        return sum(r) - sum(l-1);   
    }
};

const int N = 2e5 + 5;
int r[N], c[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    FenwickTree fullRows(n), fullCols(n);
    fori(i,0,q) {
        int t; cin >> t;
        if(t == 1 || t == 2) {
            int x, y;
            cin >> x >> y;
            if(t == 1) {
                if(!r[x]) fullRows.add(x, 1);
                if(!c[y]) fullCols.add(y, 1);
                r[x]++, c[y]++;
            }
            else {
                r[x]--, c[y]--;
                if(!r[x]) fullRows.add(x, -1);
                if(!c[y]) fullCols.add(y, -1);
            }
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int ok = fullRows.qry(x1, x2) == x2-x1+1
                || fullCols.qry(y1, y2) == y2-y1+1;
            cout << (ok ? "Yes" : "No") << endl;
        }
    }
    return 0; 
}