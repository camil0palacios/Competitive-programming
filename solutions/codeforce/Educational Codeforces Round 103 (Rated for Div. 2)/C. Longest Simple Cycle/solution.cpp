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

const int Mxn = 1e5 + 5;
ll c[Mxn], a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> c[i];
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) {
            cin >> b[i];
            if(b[i] < a[i]) swap(a[i], b[i]);
        }
        ll ans, cur;
        ans = cur = -1e18; 
        fori(i,1,n) {
            cur = a[i] == b[i] ? 1 : max(b[i]-a[i]+1, cur + c[i-1]-(b[i]-a[i]-1));
            ans = max(ans, cur + c[i]);
        }
        cout << ans << endl;
    }
    return 0; 
}