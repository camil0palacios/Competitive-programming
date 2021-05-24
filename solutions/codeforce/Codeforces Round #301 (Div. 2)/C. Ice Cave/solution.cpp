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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
const int Mxn = 505;
int n, m;
string a[Mxn];
int r1, c1, r2, c2;

bool dfs(int x, int y) {
    if(a[x][y] != '.') return x == r2 && y == c2;
    a[x][y] = 'X';
    fori(i,0,4) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if(mx >= 0 && mx < n && my >= 0 && my < m && dfs(mx, my))
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,0,n) cin >> a[i];
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    a[r1][c1] = '.';
    cout << (dfs(r1,c1) ? "YES" : "NO") << endl;
    return 0; 
}