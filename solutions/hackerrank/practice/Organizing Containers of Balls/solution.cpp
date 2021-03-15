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
int a[Mxn], b[Mxn];

void solve() {
    int n;
    cin >> n;
    fori(i,0,n) a[i] = b[i] = 0;
    fori(i,0,n) fori(j,0,n) {
        int x; cin >> x;
        a[i] += x;
        b[j] += x;
    }
    sort(a, a+n);
    sort(b, b+n);
    bool ok = 1;
    fori(i,0,n) ok &= a[i] == b[i];
    cout << (ok ? "Possible" : "Impossible") << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) solve();
    return 0; 
}