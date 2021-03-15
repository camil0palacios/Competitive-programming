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
typedef vector<ll> vll;

const int Mxn = 1e6 + 5;
ll a[Mxn];

bool check(int i) {
    if(a[i] <= a[i-1] && a[i] <= a[i+1]) return 1;
    if(a[i] >= a[i-1] && a[i] >= a[i+1]) return 1;
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll dp[n + 1], pre = 1;
    memset(dp, 0, sizeof dp);
    fore(i,1,n) {
        cin >> a[i];
    }
    fore(i,2,n) {
        dp[i] = max(dp[pre-1] + abs(a[i]-a[pre]), dp[pre] + abs(a[i]-a[pre+1]));
        if(check(i)) pre = i;
    }
    cout << dp[n] << endl;
    return 0; 
}