#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int mod = 1e9 + 7;
const int Mxn = 1e5 + 5;
const int Mxa = 75;
ll pow2[Mxn];
int f[Mxa];

int p[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int bitmask(int x) {
    int msk = 0;
    for(int j = 0; j < 19; j++) {
        while(x % p[j] == 0) {
            x /= p[j];
            msk ^= (1 << j);
        }
    }
    return msk;
}

ll dp1[1 << 19], dp2[1 << 19];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    pow2[0] = 1;
    fore(i,1,n) {
        int x; cin >> x;
        f[x]++;
        pow2[i] = (pow2[i-1]*2LL) % mod;
    }
    dp1[0] = 1;
    fore(i,1,70) {
        if(f[i]) {
            int msk = bitmask(i);
            fori(j,0,1 << 19) {
                dp2[j] = pow2[f[i]-1]*(dp1[j] + dp1[j^msk]) % mod;
            }
            swap(dp1, dp2); 
        }
    }
    ll ans = (dp1[0] - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}