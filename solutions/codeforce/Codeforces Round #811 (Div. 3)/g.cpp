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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 2e5 + 5;
int a[N], b[N];
vi g[N];
int r[N];
vl p;

void dfs(int u, ll A, ll B) {
    p.eb(B);
    r[u] = upper_bound(all(p), A) - p.begin();
    for(auto & v : g[u]) {
        dfs(v, A + a[v], B + b[v]);
    }
    p.pop_back();
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        p.clear();
        fore(i,1,n+1) g[i].clear(), r[i] = 0;
        fore(i,2,n) {
            int p;
            cin >> p >> a[i] >> b[i];
            g[p].push_back(i);
        }
        dfs(1, 0, 0);
        fore(i,2,n) cout << r[i]-1 << ' ';
        cout << endl;
    }
    return 0; 
}