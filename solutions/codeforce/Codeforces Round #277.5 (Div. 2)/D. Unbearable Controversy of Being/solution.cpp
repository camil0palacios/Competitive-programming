#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

const int Mxn = 3005;
vi g[Mxn];
vi x[Mxn];
int ans = 0;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v);
    }
    fori(i,0,n) {
        for(auto & v: g[i]) {
            for(auto & w: g[v]) {
                if(w != i) {
                    x[w].eb(i);
                }
            }
        }
    } 
    ll ans = 0;
    fori(i,0,n) {
        int lst = -1, t = 0;
        fori(j,0,sz(x[i])) {
            if(lst == -1) lst = x[i][j]; 
            else if(lst != x[i][j]) {
                ans += 1LL*t*(t-1)/2;
                t = 0;
            }
            lst = x[i][j];
            t++;
        }
        ans += 1LL*t*(t-1)/2;
    }
    cout << ans << endl;
    return 0; 
}
/* 
7 9
1 2
1 5
1 6
2 3
3 4
5 3
5 7
6 7
7 4
 */