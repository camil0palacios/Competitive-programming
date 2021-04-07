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

const int N = 203, M = 200*27;
int dp[N][M];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) dp[i][j] = INT_MIN;
    dp[0][0] = 0;
    int n, kk;
    cin >> n >> kk;
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        int t = 0, f = 0;
        while(a % 5ll == 0) f++, a /= 5ll;
        while(a % 2ll == 0) t++, a /= 2ll;
        for(int j = i+1; j >= 1; j--) {
            for(int k = M-1; k >= f; k--) {
                dp[j][k] = max(dp[j][k], dp[j-1][k-f] + t);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < M; i++) ans = max(ans, min(i, dp[kk][i]));
    cout << ans << endl;
    return 0; 
}