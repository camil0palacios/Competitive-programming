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

int dp[5010][5010];

int go(int a, int b) {
    if(a == 0 || b == 0 || (a == 1 && b == 1)) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    int ans = 0;
    if(a == 1) ans = go(a+1, b-2) + 1;
    else if(b == 1) ans = go(a-2, b+1) + 1;
    else ans = max(go(a+1, b-2),  go(a-2, b+1)) + 1;
    return dp[a][b] = ans; 
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << go(a, b) << endl;
    return 0; 
}