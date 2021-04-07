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
int f[Mxn];
int a[Mxn], b[Mxn];

void solve() {
    int n, c;
    cin >> n >> c;
    fore(i,1,n) f[i] = 0, a[i] = 0;
    int acc = 0;
    bool ok = 1;
    fore(i,1,n-1) {
        bool t = 0;
        forr(j,n,i) {
            if(acc + (j - i + 1) + (n - i - 1) <= c) {
                f[i] = j;
                acc += (j - i + 1);
                t = 1;
                break;
            }
        }
        ok &= t;
    }
    fore(i,1,n) if(!f[i]) f[i] = n;
    if(acc == c && ok) {
        fore(i,1,n) a[i] = i;
        forr(i,n,1) {
            int l = min(f[i], i);
            int r = max(f[i], i);
            reverse(a+l, a+r+1);
        }
        fore(i,1,n) {
            if(i > 1) cout << ' ';
            cout << a[i];
        }
        cout << endl;
    } else cout << "IMPOSSIBLE" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}