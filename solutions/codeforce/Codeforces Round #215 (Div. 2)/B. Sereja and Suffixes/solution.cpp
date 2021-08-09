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
int a[Mxn], f[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    fori(i,0,n) cin >> a[i];
    set<int> s;
    forr(i,n-1,0) {
        s.insert(a[i]);
        f[i] = sz(s);
    }
    fori(i,0,q) {
        int l; cin >> l;
        l--;
        cout << f[l] << endl;
    }
    return 0; 
}