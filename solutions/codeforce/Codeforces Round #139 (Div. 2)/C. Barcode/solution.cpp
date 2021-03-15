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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 1010;
int n, m, x, y;
int p[Mxn];
int dp[Mxn][2];
string a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> x >> y;
    fori(i,0,n) cin >> a[i];
    fori(j,0,m) {
        int s = 0;
        fori(i,0,n) s += a[i][j] == '#';
        p[j] = s;
    }
    fori(i,1,m) p[i] += p[i-1];
    fori(i,0,m) dp[i][0] = dp[i][1] = 1e9;
    dp[m][0] = dp[m][1] = 0;
    forr(i,m-1,0) {
        fori(j,i,m) {
            int w = j - i + 1;
            if(x <= w && w <= y) {
                int black = p[j] - (i ? p[i-1] : 0);
                int white = n*w - black;
                dp[i][0] = min(dp[i][0], dp[j+1][1] + black);
                dp[i][1] = min(dp[i][1], dp[j+1][0] + white);
            }
        }
    }
    cout << min(dp[0][0], dp[0][1]) << endl;
    return 0; 
}