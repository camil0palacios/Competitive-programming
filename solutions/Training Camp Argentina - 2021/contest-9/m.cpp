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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi c(n), d(n);
    fori(i,0,n) cin >> c[i];
    fori(i,0,n) cin >> d[i];
    vi d1, d2;
    fori(i,1,n) {
        d1.eb(c[i]-c[i-1]);
        d2.eb(d[i]-d[i-1]);
    }
    sort(all(d1)), sort(all(d2));
    cout << (d1 == d2 && c[0] == d[0] ? "Yes" : "No") << endl;
    return 0; 
}