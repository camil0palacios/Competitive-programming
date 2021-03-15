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
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1e9+7;
const int Mxn = 150005;
int n[4];
int a[4][Mxn];
map<int, int> s[Mxn];
ii re[Mxn];
priority_queue<ii, vii, greater<ii>> q;
int top;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i,0,4) cin >> n[i];
    fori(i,0,4) fore(j,1,n[i]) cin >> a[i][j];
    fori(i,1,4) {
        fore(j,1,n[i]) s[j].clear();
        while(!q.empty()) q.pop();
        int m; cin >> m;
        fori(j,0,m) {
            int x, y; cin >> x >> y;
            // x--, y--;
            s[y][x] = 1;
        }
        fore(j,1,n[i-1]) q.emplace(a[i-1][j], j);
        fore(j,1,n[i]) {
            while(!q.empty() && s[j][q.top().sd]) {
                re[++top] = q.top(); q.pop();
            }
            if(!q.empty()) a[i][j] += q.top().ft;
            else a[i][j] = oo;
            while(top) q.push(re[top--]);
        }
    }
    // fori(i,0,3) fori(j,0,n[i]) dp[i][j] = oo;
    // fori(i,0,n[3]) dp[3][i] = a[3][i];
    // forr(i,2,0) fori(j,0,n[i]) fori(k,0,n[i+1]) {
    //     if(!m[i].count({j, k})) 
    //         dp[i][j] = min(dp[i][j], dp[i+1][k] + a[i][j]);
    // }
    int ans = oo;
    fore(i,1,n[3]) ans = min(ans, a[3][i]);
    cout << (ans >= oo ? -1 : ans)  << endl;
    return 0;
}