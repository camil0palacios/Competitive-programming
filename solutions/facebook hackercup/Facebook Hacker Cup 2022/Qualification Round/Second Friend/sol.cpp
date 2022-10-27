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

const int N = 110;
char a[N][N];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    bool has = 0;
    fori(i,0,n) fori(j,0,m) {
        cin >> a[i][j];
        if(a[i][j] == '^') has = 1;
    }
    if(!has) {
        cout << "Possible" << endl;
        fori(i,0,n) {
            fori(j,0,m) cout << a[i][j];
            cout << endl;
        }
        return;
    }
    fori(i,0,n) fori(j,0,m) a[i][j] = '^';
    bool ok = 1;
    fori(i,0,n) fori(j,0,m) {
        int cnt = 0;
        fori(k,0,4) {
            int mx = i + dx[k];
            int my = j + dy[k];
            if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] == '^') {
                cnt++;
            }
        }
        ok &= cnt >= 2;
    }
    if(ok) {
        cout << "Possible" << endl;
        fori(i,0,n) {
            fori(j,0,m) cout << a[i][j];
            cout << endl;
        }
    } else cout << "Impossible" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}