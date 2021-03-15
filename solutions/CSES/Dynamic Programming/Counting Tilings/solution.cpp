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
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const int Mxn = 15;
const int Mxm = 1005;
int n, m;
ll dp[Mxm][1 << Mxn];

// bool check(int x, int y) {
//     int i = 0;
//     while(i < n) {
//         int a = (x >> i) & 1, b = (y >> i) & 1;
//         if(a && b) return 0;
//         if((!a && b) || (a && !b)) i++;
//         else {
//             if(i+1 < n) {
//                 a = (x >> (i+1)) & 1, b = (y >> (i+1)) & 1;
//                 if(!a && !b) i += 2;
//                 else return 0;
//             }
//             else return 0;
//         }
//     }
//     return 1;
// }

// ll go(int i, int msk) {
//     if(i == m) return msk == 0;
//     if(dp[i][msk] != -1) return dp[i][msk];
//     ll ans = 0;
//     fori(nsmk, 0, 1 << n) {
//         if(check(msk, nsmk)) ans = (ans + go(i + 1, nsmk)) % mod;
//     }
//     return dp[i][msk] = ans;
// }

void calc (int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
    if (x == n)
        return;
    if (y >= m) {
        dp[x+1][next_mask] += dp[x][mask];
        dp[x+1][next_mask] %= mod;
    } else {
        int my_mask = 1 << y;
        if (mask & my_mask)
            calc (x, y+1, mask, next_mask);
        else
        {
            calc (x, y+1, mask, next_mask | my_mask);
            if (y+1 < m && ! (mask & my_mask) && ! (mask & (my_mask << 1)))
                calc (x, y+2, mask, next_mask);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    swap(n, m);
    dp[0][0] = 1;
    for (int x=0; x<n; ++x)
        for (int mask=0; mask<(1<<m); ++mask)
            calc (x, 0, mask, 0);

    cout << dp[n][0] << endl;
    // memset(dp, -1, sizeof dp);
    // cout << go(0,0) << endl;
    return 0; 
}