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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;
const int Mxn = 2e5 + 5;
int b[Mxn];
map<ll, ll> dp;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> b[i];
        dp.clear();
        dp[0] = 1;
        ll ans = 0, j = 0, cur = 1;
        fore(i,1,n) {
            ll x = dp[j]; dp[j] = cur; j -= b[i];
            cur = (2*cur - x + mod) % mod;
        }
        cout << cur << endl;
    }
    return 0; 
}