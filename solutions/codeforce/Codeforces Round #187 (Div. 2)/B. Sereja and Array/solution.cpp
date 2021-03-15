#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi a(n+1);
    vll p(n+1, 0);
    fore(i,1,n) cin >> a[i];
    ll acc = 0;
    fore(i,1,m) {
        int t; cin >> t;
        if(t == 1) {
            int vi; ll xi; 
            cin >> vi >> xi;
            a[vi] = xi;
            p[vi] = acc;
        } else if(t == 2) {
            ll yi; 
            cin >> yi;
            acc += yi;
        } else {
            int qi; cin >> qi;
            cout << a[qi] + (acc - p[qi]) << endl;            
        }
    }
    return 0; 
}