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

struct dsu {
    vi p;
    dsu(int n) { p.resize(n); fori(i,0,n) p[i] = i; }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) {
            p[b] = a;
            return 1;
        }
        return 0;
    }
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu mo(n), di(n);
    fori(i,0,m1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        mo.join(u, v);
    }
    fori(i,0,m2) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        di.join(u, v);    
    }
    vii ans;
    fori(i,0,n) {
        fori(j,i+1,n) {
            if(mo.find(i) != mo.find(j) && di.find(i) != di.find(j)) {
                mo.join(i, j);
                di.join(i, j);
                ans.eb(i+1, j+1);
            }
        }
    }
    cout << sz(ans) << endl;
    for(auto & e : ans) {
        cout << e.ft << ' ' << e.sd << endl;
    }
    return 0;
}