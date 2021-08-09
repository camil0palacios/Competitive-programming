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

int eval(vi & a) {
    int n = sz(a), ans = 0;
    fori(i,1,n) ans += a[i-1] <= a[i];
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi h(n);
        fori(i,0,n) cin >> h[i];
        sort(all(h));
        int mn = 1e9;
        int idx = 0;
        fori(i,1,n) {
            int x = h[i]-h[i-1];
            if(x < mn) {
                mn = x;
                idx = i;
            }
        }
        int fst = h[idx-1], lst = h[idx];
        vi x, y;
        fori(i,0,idx-1) x.eb(h[i]);
        fori(i,idx+1,n) y.eb(h[i]);
        vi nh;
        nh.eb(h[idx-1]);
        fori(i,0,sz(x)) nh.eb(x[i]);
        fori(i,0,sz(y)) nh.eb(y[i]);
        nh.eb(h[idx]);
        vi ans = nh;
        int mx = eval(nh);
        nh.clear(), x.clear(), y.clear();
        fori(i,idx+1,n) x.eb(h[i]);
        fori(i,0,idx-1) y.eb(h[i]);
        nh.eb(h[idx-1]);
        fori(i,0,sz(x)) nh.eb(x[i]);
        fori(i,0,sz(y)) nh.eb(y[i]);
        nh.eb(h[idx]); 
        if(eval(nh) > mx) ans = nh;
        fori(i,0,n) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0; 
}