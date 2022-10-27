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

int popcount(ll n) {
    int cnt = 0;
    while(n) cnt += (n & 1), n >>= 1;
    return cnt;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll f[16];
    f[0] = 1;
    fori(i,1,16) f[i] = f[i-1]*i;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int ans = popcount(n);
        fori(msk, 0, 1 << 16) {
            ll tmp = 0;
            fori(i,0,16) {
                if(!((msk >> i) & 1)) continue;
                tmp += f[i];
            }
            if(tmp <= n) {
                int x = popcount(msk);
                int y = popcount(n-tmp);
                ans = min(ans, x + y);
            }
        }
        cout << ans << endl;
    }
    return 0; 
}