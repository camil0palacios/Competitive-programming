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

const int N = 2e5 + 5;
int a[N];
ll dp[N];

ll dist(int x1, int y1, int x2, int y2) {
    ll d = y1 - y2;
    return abs(x1-x2) + d*d;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    dp[0] = 0;
    fori(i,1,n) {
        dp[i] = 1e18;
        fore(j,1,k) {
            if(i < j) break;
            dp[i] = min(dp[i], dp[i-j] + dist(a[i], i, a[i-j], i-j));
        }
    }
    cout << dp[n-1] << endl;
    return 0; 
}