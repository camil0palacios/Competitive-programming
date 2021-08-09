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
int n, m;
ll a[Mxn], b[Mxn];

ll dist(int b1, int b2, int a1) {
    if(a1 < b1) return b2 - a1;
    if(a1 > b2) return a1 - b1;
    return min(a1-b1, b2-a1) + b2-b1;
}

bool check(ll x) {
    int i = 0, j = 0;
    fori(i,0,n) {
        if(dist(b[r],a[i],a[i]) > x) return 0; 
        int j = r;
        while(j < m && dist(b[r],b[j],a[i]) <= x) j++;
        r = j;
    }
    return r == m;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,0,n) cin >> a[i];
    fori(i,0,m) cin >> b[i];
    ll l = 0, r = 1e10;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }
    cout << r+1 << endl;
    return 0; 
}