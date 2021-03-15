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
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

struct Dsu {
    vi p;
    Dsu(int n) {
        p.assign(n, -1);
        fori(i,0,n) p[i] = i;
    }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) p[b] = a;
    }
};

const int Mxn = 110;
int x[Mxn], y[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> x[i] >> y[i];
    Dsu ds(n);
    fori(i,0,n) {
        fori(j,0,n) {
            if(i == j) continue;
            if(x[i] == x[j] || y[i] == y[j]) ds.join(i, j);
        }
    }
    set<int> s;
    fori(i,0,n) s.insert(ds.find(i));
    cout << sz(s) - 1 << endl;
    return 0; 
}