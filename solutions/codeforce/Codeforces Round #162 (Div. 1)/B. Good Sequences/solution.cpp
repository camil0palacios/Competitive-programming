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

const int Mxn = 1e5 + 5;
int a[Mxn];
int dp[Mxn], idx[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) cin >> a[i];
    int ans = 0;
    fore(i,1,n) {
        for(int j = 1; j*j <= a[i]; j++) {
            if(a[i] % j == 0) {
                dp[i] = max(dp[i], dp[idx[a[i]/j]] + 1);
                if(j > 1) dp[i] = max(dp[i],  dp[idx[j]] + 1);
                ans = max(ans, dp[i]);
                idx[j] = idx[a[i]/j] = i;
            }
        }
    }
    cout << ans << endl;
    return 0; 
}