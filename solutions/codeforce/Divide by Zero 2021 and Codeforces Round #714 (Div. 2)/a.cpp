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

void solve() {
    int n, k;
    cin >> n >> k;
    int p = n/2;
    if(n % 2 == 0) p--;
    if(p < k) {
        cout << -1 << endl;
        return;
    }
    vi ans(n);
    for(int i = 1, cnt = 0, x = n; i < n && cnt < k; i+=2, cnt++, x--) {
        ans[i] = x;
    }
    int x = 1;
    forr(i,n-1,0) {
        if(ans[i]) continue;
        ans[i] = x++;
    }
    fori(i,0,n) cout << ans[i] << ' ';
    cout << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}