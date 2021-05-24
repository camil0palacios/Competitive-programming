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
int a[Mxn];
int bg[Mxn], ed[Mxn];
int dp[Mxn];

int go(int i) {
    if(i >= n+1) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = go(i+1);
    if(bg[a[i]] == i) {
        int l = i, r = ed[a[i]], ok = 1;
        int acc = 0;
        vi vis(Mxn);
        while(l <= r) {
            if(bg[a[l]] >= i) r = max(r, ed[a[l]]);
            else { ok = 0; break; }
            if(!vis[a[l]]) {
                vis[a[l]] = 1;
                acc ^= a[l];
            }
            l++;
        }
        if(ok) ans = max(ans, go(r+1) + acc);
    }
    return dp[i] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fore(i,1,n) cin >> a[i];
    fore(i,1,n) ed[a[i]] = i;
    forr(i,n,1) bg[a[i]] = i;
    memset(dp, -1, sizeof dp);
    cout << go(1) << endl;
    return 0; 
}