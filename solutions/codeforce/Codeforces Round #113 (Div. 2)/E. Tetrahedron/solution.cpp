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

const int mod = 1e9 + 7;
const int Mxn = 1e7 + 5;

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

ll dp[4], dp_old[4];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    dp_old[0] = 1;
    forr(i,n-1,0) {
        fori(j,0,4) {
            fori(k,0,4) {
                if(j != k) add(dp[j], dp_old[k]);
            }
        }
        memcpy(dp_old, dp, sizeof dp);
        memset(dp, 0, sizeof dp);
    }
    cout << dp_old[0] << endl;
    return 0; 
}