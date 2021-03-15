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
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

string s;
int dp[10][2][2][2];

int go(int idx, int top, int z, int ok) {
    if(idx == sz(s)) return z && ok;
    if(dp[idx][top][z][ok] != -1) return dp[idx][top][z][ok];
    int ans = 0;
    int mx = top ? s[idx] - '0' : 1;
    fore(i,0,mx) {
        ans += go(idx + 1, top && i == mx, z || i != 0, ok && (i == 0 || i == 1));  
    }
    return dp[idx][top][z][ok] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << go(0,1,0,1) << endl;
    return 0; 
}