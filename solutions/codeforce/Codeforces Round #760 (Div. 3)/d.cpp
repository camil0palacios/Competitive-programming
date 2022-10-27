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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int oo = 1e9;
const int Mxn = 110;
int a[Mxn], d[Mxn];
int dp[Mxn*Mxn][55];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) d[i] = 0;
        fori(i,0,n) cin >> a[i];
        sort(a, a+n);
        int ans = 0;
        int p = k;
        forr(i,n-1,0) {
            if(p) {
                int id = n-k-1, mn = oo;
                forr(j,n-k-1,0) {
                    if(i == j) continue;
                    if(!d[j] && a[i] == a[j]) {
                        mn = 1, id = j;
                        break;
                    }
                    if(!d[j] && a[j]/a[i] < mn) {
                        mn = a[j]/a[i], id = j;
                    }
                }
                ans += mn;
                d[i] = d[id] = 1;
                p--;
            } 
            else if(!d[i]) ans += a[i], d[i] = 1;
        }
        cout << ans << endl;
    }
    return 0; 
}