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
int n, l, r, ql, qr;
ll w[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> l >> r >> ql >> qr;
    fore(i,1,n) cin >> w[i];
    fore(i,1,n) w[i] += w[i-1];
    ll ans = 1e18;
    fore(i,0,n) {
        ll x = w[i]*l + (w[n] - w[i])*r;
        if(i > n-i) x += (2*i - n - 1)*ql;
        if(i < n-i) x += (n - 2*i - 1)*qr;
        ans = min(ans, x);
    }
    cout << ans << endl;
    return 0; 
}