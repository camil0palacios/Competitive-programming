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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n);
        fori(i,0,n) cin >> a[i];
        if(n == 2) {
            cout << 0 << endl;
            continue;
        }
        ll mov = 0;
        fori(i,1,n) {
            mov += abs(a[i]-a[i-1]);
        }
        ll ans = mov;
        fori(i,0,n) {
            if(i == 0) ans = min(ans, mov - abs(a[0]-a[1]));
            else if(i == n-1) ans = min(ans, mov - abs(a[n-2]-a[n-1]));
            else ans = min(ans, mov - abs(a[i]-a[i-1]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1]));
        }
        cout << ans << endl;
    }
    return 0; 
}