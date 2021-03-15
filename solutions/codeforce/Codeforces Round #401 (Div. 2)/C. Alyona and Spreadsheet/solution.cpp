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

const int Mxn = 100005;
int a[Mxn], b[Mxn], g[Mxn];
int p[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) {
        fori(j,0,m) {
            int x; cin >> x;
            if(a[j] > x) b[j] = i;
            a[j] = x;
        }
        int mn = b[0];
        fori(j,1,m) mn = min(mn, b[j]); 
        g[i] = mn;
    }
    int q;
    cin >> q;
    fori(i,0,q) {
        int l, r; cin >> l >> r;
        cout << (g[r-1] <= l-1 ? "Yes" : "No") << endl;
    }
    return 0;
}