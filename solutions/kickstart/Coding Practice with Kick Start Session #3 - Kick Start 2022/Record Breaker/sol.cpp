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

const int N = 2e5 + 5;
int a[N];

void solve() {
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    int ans = 0, mx = -1;
    fori(i,0,n) {
        if(i == 0) ans += i+1 < n && a[i+1] < a[i];
        else if(i == n-1) ans += mx < a[i];
        else ans += mx < a[i] && a[i+1] < a[i];
        mx = max(mx, a[i]);
    }
    cout << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}