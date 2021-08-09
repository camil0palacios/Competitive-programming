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

const int Mxn = 1e5 + 5;
int a[Mxn][31], p[Mxn][31];

struct Query { 
    int l, r, bit; 
    Query(){}
    Query(int l, int r, int bit): l(l), r(r), bit(bit) {}
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Query> z;
    fori(i,0,m) {
        int l, r, q;
        cin >> l >> r >> q;
        fori(j,0,31) {
            if((q >> j)&1) a[l][j]++, a[r+1][j]--;
            else z.eb(l, r, j); 
        }
    }
    fori(j,0,31) {
        int s = 0;
        fore(i,1,n) {
            s += a[i][j];
            p[i][j] = p[i-1][j];
            if(s) a[i][j] = 1, p[i][j] += a[i][j];
            else a[i][j] = 0;
        }
    }
    bool ok = 1;
    fori(i,0,sz(z)) {
        int l = z[i].l, r = z[i].r, bit = z[i].bit;
        ok &= p[r][bit] - p[l-1][bit] < r-l+1;
    }
    if(ok) {
        cout << "YES" << endl;
        fore(i,1,n) {
            int x = 0;
            fori(j,0,31) if(a[i][j]) x |= 1 << j;
            cout << x << ' '; 
        }
        cout << endl;
    } else cout << "NO" << endl;
    return 0; 
}