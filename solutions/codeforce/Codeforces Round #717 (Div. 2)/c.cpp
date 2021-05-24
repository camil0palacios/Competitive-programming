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

const int Mxn = 105;
const int Mxs = Mxn*2002;
int n, a[Mxn];
int dp[Mxn][Mxs];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    int s = 0;
    fore(i,1,n) {
        cin >> a[i];
        s += a[i];
    }
    if(s & 1) { cout << 0 << endl; return 0; }
    s /= 2;
    int id = 1, mn = 1e9;
    dp[0][0] = 1;
    fore(i,1,n) {
        fore(j,0,s) if(a[i] <= j) dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i]];
        int cnt = 0;
        while(a[i] % 2 == 0) a[i] /= 2, cnt++;
        if(cnt < mn) mn = cnt, id = i;
    }
    if(dp[n][s]) cout << 1 << endl << id << endl;
    else cout << 0 << endl;
    return 0; 
}