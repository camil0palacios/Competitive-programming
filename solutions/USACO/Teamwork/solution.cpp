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

const int Mxn = 1e4 + 5;
ll a[Mxn];
ll dp[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    forr(i,n-1,0) {
        ll mx = 0;
        fori(j,i,min(i+k, n)) {
            mx = max(mx, a[j]);
            dp[i] = max(dp[i], dp[j+1] + 1ll*mx*(j-i+1));
        }
    }
    cout << dp[0] << endl;
    return 0; 
}