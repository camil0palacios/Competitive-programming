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
        p.assign(n, 0);
        fori(i,0,n) p[i] = i;
    }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return 1;
        p[b] = a;
        return 0;
    }
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        Dsu dsu(n);
        int ans = 0;
        fori(i,0,m) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if(x == y) continue;
            if(dsu.find(x) == dsu.find(y)) ans++;
            dsu.join(x, y);
            ans++;
        }
        cout << ans << endl;
    }
    return 0; 
}