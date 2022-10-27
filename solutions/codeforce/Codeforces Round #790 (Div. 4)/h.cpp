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
int n;
int a[N];
int bit[N];

void add(int i, int x) {
    for(; i <= n; i += i & -i) bit[i] += x;
}
int sum(int i) {
    int s = 0;
    for(; i; i -= i & -i) s += bit[i];
    return s;
}
int qry(int l, int r) {
    return sum(r) - sum(l-1);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fore(i,0,n) bit[i] = 0;
        fore(i,1,n) cin >> a[i];
        ll ans = 0;
        forr(i,n,1) {
            ans += qry(1, a[i]);
            add(a[i], 1);
        }
        cout << ans << endl;
    }
    return 0; 
}