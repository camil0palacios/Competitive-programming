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

ll l, r;
ll dp[64][2][2][2][2];

ll go(int idx, bool mxa, bool mna, bool mxb, bool mnb) {
    if(idx == -1) return 0;
    ll & ans = dp[idx][mxa][mna][mxb][mnb];
    if(ans == -1) {
        ans = 0;
        int tmxa = mxa ? (r >> idx) & 1 : 1;
        int tmna = mna ? (l >> idx) & 1 : 0;
        int tmxb = mxb ? (r >> idx) & 1 : 1;
        int tmnb = mnb ? (l >> idx) & 1 : 0;
        fore(i,tmna,tmxa) {
            fore(j,tmnb,tmxb) {
                ans = max(ans, go(idx-1, mxa && i == tmxa, mna && i == tmna, 
                    mxb && j == tmxb, mnb && j == tmnb) + (1ll*(i^j) << idx));
            }
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> l >> r;
    memset(dp, -1, sizeof dp);
    cout << go(62,1,1,1,1) << endl;
    return 0; 
}