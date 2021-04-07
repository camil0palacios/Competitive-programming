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
int n;
ll a[Mxn];

void solve() {
    cin >> n;
    fori(i,0,n) cin >> a[i];
    set<int> s;
    fori(i,1,n) s.insert(a[i]-a[i-1]);
    if(sz(s) > 2) cout << -1 << endl;
    else if(sz(s) <= 1) cout << 0 << endl;
    else {
        int x = *s.begin();
        int y = *s.rbegin();
        int m = abs(x-y);
        fori(i,0,n) {
            if(a[i] >= m) {
                cout << -1 << endl;
                return;
            }
        }
        cout << m << ' ' << max(x, y) << endl;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}