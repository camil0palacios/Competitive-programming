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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
ll a[Mxn], b[Mxn];

void solve() {
    int n; ll A, B;
    cin >> A >> B >> n;
    fori(i,0,n) cin >> a[i];
    fori(i,0,n) cin >> b[i];
    vii s(n);
    fori(i,0,n) s[i].ft = a[i], s[i].sd = b[i];
    sort(all(s));
    fori(i,0,n) a[i] = s[i].ft, b[i] = s[i].sd;
    fori(i,0,n) {
        if(B <= 0) {
            cout << "NO" << endl;
            return;
        }
        int x = (b[i] + A - 1) / A;
        if(B - a[i]*(x-1) <= 0 && b[i] - A*(x-1) > 0) {
            cout << "NO" << endl;
            return;
        }
        B -= a[i]*x;
    }
    cout << "YES" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}