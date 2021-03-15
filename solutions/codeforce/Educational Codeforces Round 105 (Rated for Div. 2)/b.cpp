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

void solve() {
    int n, u, r, l, d;
    cin >> n >> u >> r >> d >> l;
    int tu = max(0, u - (n-2));
    int tr = max(0, r - (n-2));
    int td = max(0, d - (n-2));
    int tl = max(0, l - (n-2));
    ii p[4] = {{0,0}, {0,1}, {1,0}, {1,1}};
    if(tu || td || tr || tl) {
        fori(i,0,1 << 4) {
            int row[2] = {0,0};
            int col[2] = {0,0};
            fori(j,0,4) {
                if((i >> j) & 1) {
                    row[p[j].ft]++;
                    col[p[j].sd]++;
                }
            }
            if(row[0] <= u && col[0] <= l && row[1] <= d && col[1] <= r) {
                bool ok = 1;
                if(tu) ok &= tu <= row[0];
                if(td) ok &= td <= row[1];
                if(tl) ok &= tl <= col[0];
                if(tr) ok &= tr <= col[1];
                if(ok) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}