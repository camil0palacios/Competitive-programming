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

const int oo = 1e9;
const int Mxn = 5050;
int a[Mxn];
int dp[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    fore(i,0,n) fore(j,0,n) dp[i][j] = oo;
    fore(i,0,n) dp[n][i] = 0;
    int lst = n;
    forr(i,n-1,0) {
        if(a[i]) {
            forr(j,n-1,0) {
                dp[i][j] = dp[i][j+1];
                if(!a[j])
                    dp[i][j] = min(dp[i][j], dp[lst][j+1] + abs(i - j));
            }
            lst = i;
        }
    }
    cout << dp[lst][0] << endl;    
    return 0; 
}