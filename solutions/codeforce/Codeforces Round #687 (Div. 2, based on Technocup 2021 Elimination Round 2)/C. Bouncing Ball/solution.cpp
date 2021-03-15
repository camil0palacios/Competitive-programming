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
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, p, k, x, y;
        cin >> n >> p >> k;
        char a[n + 1];
        fore(i,1,n) cin >> a[i];
        cin >> x >> y;
        ll s[n + k + 1];
        memset(s, 0, sizeof s);
        ll ans = 1e18;
        for(int i = n; i > p; i--) {
            s[i] = s[i + k] + !(a[i]-'0')*x;
            ans = min(ans, y*(i - p) + s[i]);
        }
        ans = min(ans, s[p+k] + !(a[p]-'0')*x);
        cout << ans << endl;
    }
    return 0; 
}