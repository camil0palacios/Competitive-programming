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

const int Mxn = 110;
const ll oo = 1e12;
int t[Mxn], l[Mxn], r[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        int n, m;
        cin >> n >> m;
        ll tl = 0, ml = m, mr = m;
        bool ans = 1;
        fori(i,0,n) {
            ll t, l, r;
            cin >> t >> l >> r;
            mr += t - tl;
            ml -= t - tl;
            if(mr < l || r < ml) {
                ans = 0;
            }
            ml = max(l, ml);
            mr = min(r, mr);
            tl = t;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0; 
}