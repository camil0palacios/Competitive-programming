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


struct Bit {
    vi bit;
    Bit(int n) { bit.assign(n + 10, 0); }
    void add(int i, int x) {
        for(; i < bit.size(); i += (i & -i)) bit[i] += x;
    }
    int sum(int i) {
        int ans = 0;
        for(; i; i -= (i & -i)) ans += bit[i];
        return ans;
    }
    int qry(int i, int j) {
        return sum(j) - sum(i-1);
    }
};

const int Mxn = 2e5 + 5;
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> a[i], b[i] = a[i];
        sort(b+1, b+n+1);
        map<int,int> m;
        int id = 0;
        fore(i,1,n) {
            if(m.count(b[i])) continue;
            m[b[i]] = ++id;
        }
        ll ans = 0;
        Bit f(n + 10);
        fore(i,1,n) {
            int x = m[a[i]];
            int gr = f.qry(x+1, id);
            int ls = f.qry(1, x-1);
            if(gr >= ls) ans += ls;
            else ans += gr;
            f.add(x, 1);      
        }
        cout << ans << endl;
    }
    return 0; 
}