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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
int a[Mxn], b[Mxn], c[Mxn], p[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, k;
    cin >> n >> q >> k;
    fore(i,1,n) cin >> a[i];
    a[0] = 1, a[n+1] = k;
    fore(i,1,n) {
        b[i] = a[i+1] - a[i] - 1;
        c[i] = a[i] - a[i-1] - 1;
    }
    fore(i,1,n) p[i] = p[i-1] + b[i] + c[i];
    fori(i,0,q) {
        int l, r; cin >> l >> r;
        int ans = 0;
        if(l != r) {
            if(l+1 == r) ans += 2*(a[r]-a[l]-1);
            else {
                ans += p[r-1]-p[l];
                ans += b[l] + c[r];
            }
            ans += (a[l]-1) + (k - a[r]);
        } else ans = k - 1;
        cout << ans << endl;   
    }
    return 0; 
}