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

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int a[N], b[N], c[N];
int to[N], f[N], vis[N];
int p[N];

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
void join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) p[b] = a;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) p[i] = i, f[i] = 0, vis[i] = 0;
        fore(i,1,n) cin >> a[i], to[a[i]] = i;
        fore(i,1,n) {
            cin >> b[i];
            join(i, to[b[i]]);
        }
        fore(i,1,n) {
            cin >> c[i];
            if(c[i]) f[find(i)] = 1;
        }
        ll ans = 1;
        fore(i,1,n) {
            int pr = find(i);
            if(!vis[pr]) {
                ans *= f[pr] || a[i] == b[i] ? 1 : 2;
                ans %= mod;
            } 
            vis[pr] = 1;
        }
        cout << ans << endl;
    }
    return 0; 
}