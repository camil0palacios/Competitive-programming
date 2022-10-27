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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int mod = 1e9 + 7;
const int N = 4e4 + 5;
ll dp[505][N];
vi pal;

bool isPalindrome(int x) {
    string t = to_string(x);
    int n = sz(t);
    bool ok = 1;
    fori(i,0,sz(t)/2) ok &= t[i] == t[n-i-1];
    return ok;
}

void sum(ll & x, ll y) {
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i,1,N) {
        if(isPalindrome(i)) pal.eb(i);
    }
    int p = sz(pal);
    dp[p][0] = 1;
    forr(i,p-1,0) {
        fori(s,0,N) {
            sum(dp[i][s], dp[i+1][s]);
            if(pal[i] <= s) 
                sum(dp[i][s], dp[i][s-pal[i]]);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[0][n] << endl;
    }
    return 0; 
}