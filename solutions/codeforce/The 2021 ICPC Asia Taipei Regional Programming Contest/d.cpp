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

int n, k;
int dp[(1 << 16) + 2][210];
int nxt[(1 << 16) + 2][210];
int d[16];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    fori(i,0,n) cin >> d[i];
    sort(d, d+n);
    string ans; 
    forr(msk,(1 << n)-1,0) {
        fore(r,0,k) {
            if(msk == (1 << n)-1) dp[msk][r] = r;
            else {
                int & ans = dp[msk][r];
                ans = -1e9;
                forr(i,n-1,0) {
                    if(!((msk >> i) & 1)) {
                        int tmp = dp[msk | (1 << i)][(r*10 + d[i]) % k];
                        if(ans < tmp) {
                            ans = tmp;
                            nxt[msk][r] = i;
                        }
                    }
                }
            }
        }
    }
    int msk = 0, r = 0;
    while(msk != (1 << n)-1) {
        int i = nxt[msk][r];
        ans += char(d[i] + '0');
        msk = msk | (1 << i);
        r = (r*10 + d[i]) % k;
    }
    cout << ans << endl;
    return 0; 
}