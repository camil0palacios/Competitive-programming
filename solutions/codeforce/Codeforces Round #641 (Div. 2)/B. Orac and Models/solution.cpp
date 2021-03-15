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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi s(n + 1);
        fore(i,1,n) cin >> s[i];
        int ans = 0;
        vi dp(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                if(i % j == 0) {
                    if(s[j] < s[i]) dp[i] = max(dp[i], dp[j] + 1);
                    if(i / j != j && s[i/j] < s[i]) dp[i] = max(dp[i], dp[i/j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0; 
}