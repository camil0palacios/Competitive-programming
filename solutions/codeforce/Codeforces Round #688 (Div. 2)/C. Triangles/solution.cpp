#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 2020;
char a[Mxn][Mxn];

int n;
int mx_x[Mxn], mx_y[Mxn];
int mn_x[Mxn], mn_y[Mxn];
int ans[10];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,10) {
            mx_x[i] = mx_y[i] = 1;
            mn_x[i] = mn_y[i] = n;
        }
        fore(i,1,n) {
            fore(j,1,n) { 
                cin >> a[i][j];
                int d = a[i][j]-'0';
                mn_x[d] = min(mn_x[d], i);
                mx_x[d] = max(mx_x[d], i);
                mn_y[d] = min(mn_y[d], j);
                mx_y[d] = max(mx_y[d], j);
            }
        }
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int d = a[i][j]-'0';
                ans[d] = max(ans[d], (i - mn_x[d])*max(j-1, n-j));
                ans[d] = max(ans[d], (mx_x[d] - i)*max(j-1, n-j));
                ans[d] = max(ans[d], (j - mn_y[d])*max(i-1, n-i));
                ans[d] = max(ans[d], (mx_y[d] - j)*max(i-1, n-i));
            }
        }
        fori(i,0,10) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0; 
}