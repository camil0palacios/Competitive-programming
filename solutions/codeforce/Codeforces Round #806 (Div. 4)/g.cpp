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

const int N = 1e5 + 5;
const int L = 31;
int a[N];
ll dp[N][L+5];

int reduce(int x, int k) {
    while(k--) x /= 2;
    return x;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) cin >> a[i];
        fore(i,0,n) fore(j,0,L) dp[i][j] = -1e9;
        fore(i,0,L+1) dp[n][i] = 0;
        forr(i,n-1,0) {
            fore(j,0,L) {
                dp[i][j] = max(
                    dp[i+1][j] - k + reduce(a[i], j), 
                    dp[i+1][min(j+1, L)] + reduce(a[i], j+1)
                );
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0; 
}