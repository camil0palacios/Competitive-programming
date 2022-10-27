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

const int N = 110;
int n;
char a[N][N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,n) fori(j,0,n) cin >> a[i][j];
        int ans = 0;
        fori(i,0,n) fori(j,0,n) {
            int s = (a[i][j]-'0') + (a[j][n-i-1]-'0') + (a[n-j-1][i]-'0') + (a[n-i-1][n-j-1]-'0');
            ans += min(s, 4-s);
        }
        cout << ans/4 << endl;
    }
    return 0; 
}