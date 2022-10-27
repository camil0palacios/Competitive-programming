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

const int oo = 1e9;
const int Mxn = 190;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int d[Mxn][Mxn];
string a[Mxn];


int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) fori(j,0,m) d[i][j] = oo;
        queue<ii> q;
        fori(i,0,n) fori(j,0,m) {
            if(a[i][j] == '1') {
                d[i][j] = 0;
                q.emplace(i, j);
            }
        }
        while(!q.empty()) {
            int x = q.front().ft;
            int y = q.front().sd;
            q.pop();
            fori(i,0,4) {
                int mx = x + dx[i];
                int my = y + dy[i];
                if(mx >= 0 && mx < n && my >= 0 && my < m && d[x][y]+1 < d[mx][my]) {
                    d[mx][my] = d[x][y]+1;
                    q.emplace(mx, my);
                }
            }
        }
        fori(i,0,n) {
            fori(j,0,m) cout << d[i][j] << ' ';
            cout << endl;
        }
    }  
    return 0; 
}