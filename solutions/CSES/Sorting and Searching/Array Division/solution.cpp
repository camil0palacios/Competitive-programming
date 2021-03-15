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

const int Mxn = 2e5 + 5;
int n, k;
int a[Mxn];

bool can(ll x) {
    int tk = 0; ll s = 0;
    fori(i,0,n) {
        if(a[i] > x) return 0;
        if(s + a[i] > x) {
            tk++;
            s = a[i];
        } else s += a[i];
    }
    return tk <= k-1; 
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    ll s = 0;
    fori(i,0,n) cin >> a[i], s += a[i];
    ll l = 1, r = 1e18;
    while(l <= r) {
        ll m = (l + r) >> 1;
        if(can(m)) r = m-1;
        else l = m+1;
    }
    cout << r+1 << endl;
    return 0; 
}