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

int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, 1, -1, -1};
char a[8][8], b[8][8];

bool comp() {
    bool ok = 1;
    fori(i,0,8) fori(j,0,8)  ok &= a[i][j] == b[i][j];
    return ok;
}

bool check(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        fori(i,0,8) fori(j,0,8) cin >> a[i][j];
        fori(i,0,8) fori(j,0,8) {
            fori(x,0,8) fori(y,0,8) b[x][y] = '.';
            fori(k,0,4) {
                int x = i, y = j;
                while(check(x, y)) {
                    b[x][y] = '#';
                    x += dx[k], y += dy[k];
                }
            }
            if(comp()) {
                cout << i+1 << ' ' << j+1 << endl;
                break;
            }
        }
    }
    return 0; 
}