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

const int oo = 1e9;
const int Mxn = 2e5 + 5;
int dp[Mxn], pos[Mxn];
vi nxt[26];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = sz(s);
        fori(i,0,26) nxt[i].clear();
        fori(i,0,n) {
            nxt[s[i]-'a'].eb(i);
            pos[i] = sz(nxt[s[i]-'a'])-1;
        }
        fore(i,0,n) dp[i] = oo;
        dp[n] = 0;
        forr(i,n-1,0) {
            dp[i] = dp[i+1] + 1;
            if(pos[i]+1 < sz(nxt[s[i]-'a'])) { 
                int p = nxt[s[i]-'a'][pos[i]+1];
                dp[i] = min(dp[i], dp[p+1] + (p-i-1));
            }
        }
        cout << dp[0] << endl;
    }
    return 0; 
}