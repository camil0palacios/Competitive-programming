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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 4e5 + 5;
vi g[Mxn];
int r[Mxn], lvl[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) {
            g[i].clear();
            r[i] = lvl[i] = 0;
        }
        fori(i,0,n-1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].eb(v);
            g[v].eb(u);
            r[u]++, r[v]++;
        } 
        queue<int> q;
        fori(i,0,n) {
            if(r[i] == 1) q.push(i), lvl[i] = 1;
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto & v : g[u]) {
                if(r[v] != 1) { 
                    r[v]--;
                    if(r[v] == 1) q.push(v), lvl[v] = lvl[u] + 1;
                }
            }
        }
        int ans = 0;
        fori(i,0,n) if(lvl[i] > k) ans++;
        cout << ans << endl;
    }
    return 0; 
}