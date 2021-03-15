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

const int Mxn = 300005;
bool s[Mxn];
ll dp[Mxn];
vi p;

void calc() {
    memset(s, -1, sizeof s);
    s[0] = s[1] = 0;
    for(ll i = 2; i < Mxn; i++) {
        if(s[i]) {
            p.eb(i);
            for(ll j = i*i; j < Mxn; j += i) {
                s[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    calc();
    dp[0] = 1;
    fore(i,1,40) {
        dp[i] = dp[i-1];
        if(i >= 4) dp[i] += dp[i-4];
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) cout << 0 << endl;
        else {
            int l = 0, r = sz(p)-1;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(p[m] <= dp[n]) l = m+1;
                else r = m-1;
            }
            cout << l << endl;
        }
    }
    return 0; 
}