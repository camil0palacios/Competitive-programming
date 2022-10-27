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

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

int a[210][210];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        fori(i,0,n) fori(j,0,m) cin >> a[i][j];
        int ans = 0;
        fori(i,0,n) {
            fori(j,0,m) {
                int tmp = 0;
                fori(k,0,4) {
                    int x = i, y = j;
                    while(x >= 0 && x < n && y >= 0 && y < m) {
                        tmp += a[x][y];
                        x += dx[k], y += dy[k];
                    }
                    
                }
                tmp -= 3*a[i][j];
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0; 
}