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
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 10;
int n;
ii pos[Mxn];
int dp[1 << Mxn][Mxn][Mxn][2*Mxn];

// O(2^n*n^3*2n)

int dist(ii a, ii b) {
    return abs(a.ft - b.ft) + abs(a.sd - b.sd);
}

int go(int msk, int t1, int t2, int p) {
    if(msk == (1 << n)-1) return dist(pos[p], {0,0});
    auto & ans = dp[msk][t1][t2][p];
    if(ans == -1) {
        ans = 1e9;
        if(t1 || t2) {
            if(t1) ans = min(ans, go(msk|(1 << (t1-1)), 0, t2, t1) + dist(pos[p], pos[t1]));
            if(t2) ans = min(ans, go(msk|(1 << (t2-1)), t1, 0, t2) + dist(pos[p], pos[t2]));
        }
        if(!t1 || !t2) {
            fore(i,1,n) {
                if(!((msk>>(i-1))&1) && t1 != i && t2 != i) {
                    if(!t1) ans = min(ans, go(msk, i, t2, 2*n+i) + dist(pos[p], pos[2*n+i]));
                    if(!t2) ans = min(ans, go(msk, t1, i, 2*n+i) + dist(pos[p], pos[2*n+i]));
                }
            }
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    pos[0] = {0,0};
    fore(i,1,n) {
        cin >> pos[i].ft >> pos[i].sd; // cook
        cin >> pos[2*n+i].ft >> pos[2*n+i].sd; // tools
    }
    memset(dp, -1, sizeof dp);
    cout << go(0,0,0,0) << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0; 
}