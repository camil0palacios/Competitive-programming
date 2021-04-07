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
int c[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> c[i];
        ll ans = 1e18;
        ll s = 0;
        int mn[2];
        mn[0] = 1e9, mn[1] = 1e9;
        fore(i,1,n) {
            s += c[i];
            mn[i%2] = min(mn[i%2], c[i]);
            int cnt[2] = {i/2, (i+1)/2};
            if(i >= 2) {
                ans = min(ans, 1ll*(s-mn[0]-mn[1]) + 1ll*(n-(cnt[0]-1))*mn[0] + 1ll*(n-(cnt[1]-1))*mn[1]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}