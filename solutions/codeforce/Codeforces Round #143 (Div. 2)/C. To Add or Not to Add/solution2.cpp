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
int n, k;
ll a[Mxn];

bool check(int x) {
    ll s = 0; 
    fori(i,0,x) s += a[x-1] - a[i];
    if(s <= k) return 1;
    fori(i,x,n) {
        s += a[i]*x - a[i] - a[i-1]*x + a[i-x];
        if(s <= k) return 1;
    }
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    sort(a, a+n);
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid+1;
        else r = mid-1;
    }
    int x = l-1;
    cout << x << ' ';
    ll s = 0;
    fori(i,0,x) s += a[x-1] - a[i];
    if(s <= k) { cout << a[x-1] << endl; return 0; }
    fori(i,x,n) {
        s += a[i]*x - a[i] - a[i-1]*x + a[i-x];
        if(s <= k) { cout << a[i] << endl; break; } 
    }
    return 0; 
}