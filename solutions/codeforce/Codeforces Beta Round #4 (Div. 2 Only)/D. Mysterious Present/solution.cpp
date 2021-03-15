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

const int Mxn = 5005;
int n;
int w[Mxn], h[Mxn];
int dp[Mxn], res[Mxn];

int go(int i) {
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    fore(j,1,n) {
        if(w[i] < w[j] && h[i] < h[j] && ans < go(j) + 1) {
            res[i] = j;
            ans = go(j) + 1;
        }
    } 
    return dp[i] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> w[0] >> h[0];
    fore(i,1,n) cin >> w[i] >> h[i];
    memset(dp, -1, sizeof dp);
    memset(res, -1, sizeof res);
    cout << go(0) << endl;
    for(int i = 0; i != -1; i = res[i]) {
        if(i) cout << i << ' ';
    }
    cout << endl;
    return 0; 
}