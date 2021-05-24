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
int a[Mxn], b[Mxn];

void solve() {
    int n;
    cin >> n;
    fori(i,0,n+2) cin >> b[i];
    sort(b,b+n+2);
    ll s = 0;
    fori(i,0,n) s += b[i];
    bool ok = s == b[n];
    if(!ok) {
        fori(i,0,n) {
            if(s - b[i] + b[n+1] == b[n]) {
                swap(b[i], b[n+1]);
                ok = 1;
                break;
            }
        }
    }
    if(!ok) {
        swap(b[n], b[n+1]);
        ok = s == b[n];
        if(!ok) {
            fori(i,0,n) {
                if(s - b[i] + b[n+1] == b[n]) {
                    swap(b[i], b[n+1]);
                    ok = 1;
                    break;
                }
            }
        }
    }
    if(ok) {
        fori(i,0,n) cout << b[i] << ' '; 
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}