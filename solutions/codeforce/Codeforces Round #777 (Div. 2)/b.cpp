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

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

const int Mxn = 505;
int n, m;
char a[Mxn][Mxn];

void solve() {
    cin >> n >> m;
    fori(i,0,n) fori(j,0,m) cin >> a[i][j];
    bool ok = 0;
    fori(i,0,n) {
        fori(j,0,m) {
            if(a[i][j] == '0') continue;
            fori(k,0,4) {
                int mx = i + dx[k];
                int my = j + dy[k];
                if(mx >= 0 && mx < n && my >= 0 && my < m && 
                    a[mx][j] == '1' && a[i][my] == '1' && a[mx][my] == '0') {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}