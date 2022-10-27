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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 55;
char a[Mxn][Mxn];
int r[Mxn], c[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        x--, y--;
        fori(i,0,n) r[i] = 0;
        fori(i,0,m) c[i] = 0;
        bool ok = 0;
        fori(i,0,n) fori(j,0,m) {
            cin >> a[i][j];
            if(a[i][j] == 'B') r[i] = c[j] = ok = 1;
        }
        if(a[x][y] == 'B') cout << 0 << endl;
        else if(r[x] || c[y]) cout << 1 << endl;
        else if(ok) cout << 2 << endl;
        else cout << -1 << endl;
    }
    return 0; 
}