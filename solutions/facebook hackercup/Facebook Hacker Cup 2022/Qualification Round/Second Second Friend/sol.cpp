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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int N = 3010;
int n, m;
char a[N][N], b[N][N];
int cnt[N][N];
bool vis[N][N];

void possible() {
    cout << "Possible" << endl;
    fori(i,0,n) {
        fori(j,0,m) cout << b[i][j];
        cout << endl;
    }
}

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && b[x][y] == '^';
}

void clear() {
    fori(i,0,n) fori(j,0,m) {
        vis[i][j] = 0;
        cnt[i][j] = 0;
    }
}

void solve() {
    cin >> n >> m;
    bool has = 0;
    clear();
    fori(i,0,n) fori(j,0,m) {
        cin >> a[i][j];
        b[i][j] = a[i][j];
        has |= a[i][j] == '^';
    }
    if(!has) {
        possible();
        return;
    }
    fori(i,0,n) fori(j,0,m) {
        if(b[i][j] == '.') b[i][j] = '^';
    }
    queue<ii> q;
    fori(i,0,n) fori(j,0,m) {
        if(b[i][j] != '^') continue;
        fori(k,0,4) {
            int mx = i + dx[k];
            int my = j + dy[k];
            if(check(mx, my)) cnt[i][j]++;
        }
        if(cnt[i][j] < 2) {
            vis[i][j] = 1;
            q.push({i, j});
        }
    }
    while(!q.empty()) {
        int x = q.front().ft;
        int y = q.front().sd;
        b[x][y] = '.';
        q.pop();
        fori(i,0,4) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if(check(mx, my)) {
                cnt[mx][my]--;
                if(cnt[mx][my] < 2 && !vis[mx][my]) {
                    vis[mx][my] = 1;
                    q.push({mx, my});
                }
            }
        }
    }
    fori(i,0,n) fori(j,0,m) {
        if(a[i][j] == '^' && a[i][j] != b[i][j]) {
            cout << "Impossible" << endl;
            return;
        }
    }
    possible();
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