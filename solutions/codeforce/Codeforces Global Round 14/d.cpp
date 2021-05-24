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
int a[Mxn], p[Mxn];

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    fore(i,1,n) p[i] = 0;
    fori(i,0,l) {
        int x; cin >> x;
        p[x]++;
    } 
    fori(i,0,r) {
        int x; cin >> x;
        p[x]--;
    }
    int ans = 0, x = 0, y = 0;
    fore(i,1,n) {
        while(p[i] > 1 && l > r) p[i] -= 2, l--, r++, ans++;
        while(p[i] < -1 && l < r) p[i] += 2, l++, r--, ans++;
        if(p[i] < 0) x -= p[i];
        else y += p[i];
    } 
    int d = min(x, y);
    ans += d;
    x -= d, y -= d;
    ans += x+y;
    cout << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}