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
ii a[Mxn];
int h[Mxn], ans[Mxn];

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    fori(i,0,n) h[i] = 0;
    fori(i,0,n) cin >> a[i].ft, a[i].sd = i;
    sort(a, a+n, greater<ii>());
    fori(i,0,m) {
        h[i] = a[i].ft;
        ans[a[i].sd] = i;
    }
    int j = m-1;
    fori(i,m,n) {
        h[j] += a[i].ft;
        if(j < m-1) {
            if(abs(h[j] - h[j+1]) > x) {
                cout << "NO" << endl;
                return;
            }
        }
        ans[a[i].sd] = j;
        j = (j-1+m) % m;
    }
    cout << "YES" << endl;
    fori(i,0,n) cout << ans[i]+1 << ' ';
    cout << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}