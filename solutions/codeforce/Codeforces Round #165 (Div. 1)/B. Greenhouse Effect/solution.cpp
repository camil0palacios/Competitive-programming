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

const int Mxn = 5050;
int s[Mxn], dp[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) {
        double x;
        cin >> s[i] >> x;
    }
    fori(i,0,n) {
        int t = s[i];
        forr(j,t,1) {
            dp[t] = max(dp[t], dp[j]+1); 
        }
    }
    int ans = 0;
    fore(i,1,n) ans = max(ans, dp[i]);
    cout << n - ans << endl;
    return 0; 
}