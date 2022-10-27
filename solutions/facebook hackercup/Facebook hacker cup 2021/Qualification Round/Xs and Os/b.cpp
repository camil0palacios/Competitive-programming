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

const int oo = 1e9;
const int Mxn = 55;
string a[Mxn];

int pr[Mxn], pc[Mxn];
int rf[Mxn], cf[Mxn];

void clear(int n) {
    fori(i,0,n) {
        pr[i] = pc[i] = 0;
        rf[i] = cf[i] = 0;
    }
}

void solve() {
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    clear(n);
    fori(i,0,n) fori(j,0,n) 
        rf[i] |= (a[i][j] == 'O'); 
    fori(j,0,n) fori(i,0,n) 
        cf[j] |= (a[i][j] == 'O');
    fori(i,0,n) fori(j,0,n) 
        pr[i] += (a[i][j] == 'X');
    fori(j,0,n) fori(i,0,n)
        pc[j] += (a[i][j] == 'X');
    int mn = oo;
    fori(i,0,n) {
        if(rf[i]) continue;
        int f = n - pr[i];
        mn = min(mn, f);
    }
    fori(i,0,n) {
        if(cf[i]) continue;
        int f = n - pc[i];
        mn = min(mn, f);
    }
    if(mn == oo) cout << "Impossible" << endl;
    else {
        set<vii> s;
        fori(i,0,n) {
            if(rf[i]) continue;
            int f = n - pr[i];
            if(f == mn) {
                vii t;
                fori(j,0,n) if(a[i][j] == '.') t.eb(i, j);
                sort(all(t));
                s.insert(t);
            }
        }
        fori(j,0,n) {
            if(cf[j]) continue;
            int f = n - pc[j];
            if(f == mn) {
                vii t;
                fori(i,0,n) if(a[i][j] == '.') t.eb(i, j);
                sort(all(t));
                s.insert(t);
            }
        }
        cout << mn << ' ' << sz(s) << endl;
    }
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