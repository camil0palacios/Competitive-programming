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

const int N = 1010;
ll p[N][N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        fori(i,0,N) fori(j,0,N) p[i][j] = 0;
        fori(i,0,n) {
            int h, w;
            cin >> h >> w;
            p[h][w] += 1ll*h*w;
        }
        fori(i,0,N) {
            fori(j,1,N) p[i][j] += p[i][j-1];
        }
        fori(i,0,q) {
            int hl, wl, hr, wr;
            cin >> hl >> wl >> hr >> wr;
            ll ans = 0;
            fore(i,hl+1,hr-1) {
                if(wl < wr-1) 
                    ans += p[i][wr-1] - p[i][wl];
            }
            cout << ans << endl;
        }
    }
    return 0; 
}