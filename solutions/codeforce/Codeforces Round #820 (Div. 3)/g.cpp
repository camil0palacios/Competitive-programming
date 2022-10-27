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

const int mod = 1e9 + 7;
const int N = 550;
int match[N];
ll dp[N], cnt[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        int n = sz(s), m = sz(t);
        fori(i,0,n) {
            match[i] = 0;
            if(s.substr(i, m) == t) match[i] = 1;
        }
        fore(i,0,n) dp[i] = mod, cnt[i] = 0;
        dp[n] = 0, cnt[n] = 1;
        forr(i,n-1,0) {
            if(match[i]) {
                fori(j,0,m) {
                    if(!match[i+j]) continue;
                    if(match[i+j] && dp[i+j+m] + 1 < dp[i]) {
                        dp[i] = dp[i+j+m] + 1;
                        cnt[i] = 0;
                    }
                    if(dp[i+j+m] + 1 == dp[i]) cnt[i] = (cnt[i] + cnt[i+j+m]) % mod;
                }
            } else {
                dp[i] = dp[i+1];
                cnt[i] = cnt[i+1];
            }
        }
        cout << dp[0] << ' ' << cnt[0] << endl;
    }
    return 0; 
}