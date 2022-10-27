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

const int Mxn = 1e5 + 5;
int dp[Mxn], lst[2][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a[2];
        fori(i,0,2) cin >> a[i];
        lst[0][n] = lst[1][n] = -1; 
        forr(i,n-1,0) {
            lst[0][i] = lst[0][i+1];
            lst[1][i] = lst[1][i+1];
            if(a[0][i] == '0' || a[1][i] == '0') lst[0][i] = i;
            if(a[0][i] == '1' || a[1][i] == '1') lst[1][i] = i;
        }
        dp[n] = 0;
        forr(i,n-1,0) {
            dp[i] = 0;
            int c = a[0][i] - '0';
            if(a[0][i] == a[1][i]) dp[i] = dp[i+1] + (c == 0);
            if(lst[c^1][i] != -1) dp[i] = max(dp[i], dp[lst[c^1][i]+1] + 2);
        }   
        cout << dp[0] << endl;
    }
    return 0;
}