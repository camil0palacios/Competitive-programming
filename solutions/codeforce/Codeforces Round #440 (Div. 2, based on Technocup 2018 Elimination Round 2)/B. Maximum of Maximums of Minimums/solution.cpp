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
    int n, k;
    cin >> n >> k;
    vi a(n);
    fori(i,0,n) cin >> a[i];
    int mn = *min_element(all(a));
    int mx = *max_element(all(a));
    if(k == 1) cout << mn << endl;
    else if(k == 2) {
        int sf[n+1], pf[n+1];
        pf[0] = a[0], sf[n-1] = a[n-1];
        fori(i,1,n) pf[i] = min(pf[i-1], a[i]);
        forr(i,n-2,0) sf[i] = min(sf[i+1], a[i]);
        mx = mn;
        fori(i,0,n-1) {
            mx = max(mx, max(pf[i], sf[i+1]));
        } 
        cout << mx << endl;
    }
    else cout << mx << endl;
    return 0; 
}