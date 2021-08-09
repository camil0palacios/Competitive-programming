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

const double scale = 1e+6;

double rec(int c, int m, int p, int v) {
    double ans = p/scale;
    if(c > 0) {
        int d = m > 0 ? 2 : 1;
        int x = c > v ? v : c;
        ans += (c/scale)*(1 + rec(c > v ? c-v : 0, m > 0 ? m+x/d : 0, p+x/d, v));
    }
    if(m > 0) {
        int d = c > 0 ? 2 : 1;
        int x = m > v ? v : m;
        ans += (m/scale)*(1 + rec(c > 0 ? c+x/d : 0, m > v ? m-v : 0, p+x/d, v));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    while(t--) {
        double cn, mn, pn, vn;
        cin >> cn >> mn >> pn >> vn;
        int c = round(cn*scale);
        int m = round(mn*scale);
        int p = round(pn*scale);
        int v = round(vn*scale);
        cout << rec(c, m, p, v) << endl;
    }
    return 0; 
}