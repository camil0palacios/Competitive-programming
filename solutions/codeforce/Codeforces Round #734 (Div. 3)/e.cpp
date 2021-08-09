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

const int oo = 1e9;
const int Mxn = 2020;
int n, k;
int a[Mxn];
int dp[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        fore(i,1,n) cin >> a[i];
        int res = oo;
        fore(i,0,n) fore(j,0,n) dp[i][j] = 0;
        fore(i,1,n) {
            fore(dec,0,i-1) {
                int & ans = dp[i][dec];
                if(a[i] == i-dec) ans = max(ans, dp[i-1][dec] + 1);
                if(dec) ans = max(ans, dp[i-1][dec-1]);
                ans = max(ans, dp[i-1][dec]);
                if(ans >= k) res = min(res, dec);
            }
        }
        cout << (res != oo ? res : -1) << endl;
    }
    return 0; 
}