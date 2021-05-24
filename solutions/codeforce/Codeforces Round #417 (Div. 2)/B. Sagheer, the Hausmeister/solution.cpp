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

const int Mxn = 102;
string a[Mxn];
int l[Mxn], r[Mxn];
int dp[Mxn][2];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; 
    cin >> n >> m;
    m += 2;
    fori(i,0,n) cin >> a[i];
    reverse(a, a+n);
    fori(i,0,n) {
        r[i] = 0, l[i] = m-1;
        fori(j,0,m) if(a[i][j] == '1') r[i] = j;
        forr(j,m-1,0) if(a[i][j] == '1') l[i] = j;
    }
    forr(i,n-1,0) {
        if(r[i] == 0) n--;
        else break;
    }
    if(n) {
        dp[n-1][0] = min(r[n-1], m-1);
        dp[n-1][1] = min(m-l[n-1]-1, m-1);
        forr(i,n-2,0) {
            dp[i][0] = min(dp[i+1][0] + 2*r[i], dp[i+1][1] + m-1) + 1;
            dp[i][1] = min(dp[i+1][1] + 2*(m-l[i]-1), dp[i+1][0] + m-1) + 1;
        }
    }
    cout << dp[0][0] << endl;
    return 0; 
}