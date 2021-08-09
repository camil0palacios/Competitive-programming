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

const int mod = 1e9 + 7;
int n, k[2];

void get_sum(int i, int msk, ll sum, vi & a, vl & s) {
    if(i == n) { s[msk] = sum; return; }
    get_sum(i+1, msk, sum, a, s);
    get_sum(i+1, msk ^ (1 << i), sum + a[i], a, s);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    vi a(n);
    fori(i,0,n) cin >> a[i];
    vl s(1 << n);
    get_sum(0, (1 << n)-1, 0, a, s);
    int K; 
    cin >> K;
    k[0] = k[1] = -1;
    fori(i,0,K) cin >> k[i];
    vi dp(1 << n);
    dp[0] = 1;
    fori(i,0,1 << n) {
        int msk = i;
        while(msk) {
            int bit = msk & -msk;
            int nmsk = i ^ bit;
            if(s[nmsk] != k[0] && s[nmsk] != k[1]) 
                dp[i] = (dp[i] + dp[nmsk]) % mod;
            msk -= bit;
        }
    }
    cout << dp[(1 << n)-1] << endl;
    return 0;
}