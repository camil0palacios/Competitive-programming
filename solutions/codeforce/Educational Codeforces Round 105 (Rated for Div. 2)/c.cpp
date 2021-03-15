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

const int Mxn = 2e5 + 5;

int sokoban(vi & a, vi & b) {
    int n = sz(a), m = sz(b);
    int s = 0, j = 0;
    for(auto & x : b) {
        while(j < n && a[j] < x) j++;
        if(j < n && a[j] == x) s++;
    }
    j = 0;
    int ans = s, k = 0;
    fori(i,0,m) {
        while(j < n && a[j] < b[i]) j++;
        if(j < n && a[j] == b[i]) j++, s--;
        while(k < m && b[k] < b[i] - j + 1) k++;
        ans = max(ans, s + i - k + 1);
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a[2], b[2];
    fori(i,0,n) {
        int x; cin >> x;
        if(x > 0) a[0].eb(x);
        else a[1].eb(-x);
    }
    fori(i,0,m) {
        int x; cin >> x;
        if(x > 0) b[0].eb(x);
        else b[1].eb(-x);
    }
    fori(i,0,2) {
        sort(all(a[i]));
        sort(all(b[i]));
    }
    cout << sokoban(a[0], b[0]) + sokoban(a[1], b[1]) << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}