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

const int N = 210;
int a[N];
int vis[N];

ll lcm(ll x, ll y) { return x / __gcd(x, y) * y; }

void shift(string & s) {
    int n = sz(s);
    string t = s;
    fori(i,0,n) {
        t[i] = s[(i-1+n)%n];
    }
    s = t;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        fori(i,0,n) {
            cin >> a[i];
            a[i]--;
            vis[i] = 0;
        }
        ll ans = 1;
        fori(i,0,n) {
            if(vis[i]) continue;
            int u = i;
            string t, tmp;
            while(!vis[u]) {
                t += s[u];
                vis[u] = 1;
                u = a[u];
            };
            tmp = t;
            int cnt = 0;
            fore(i,1,sz(tmp)) {
                shift(tmp);
                if(t == tmp) {
                    cnt = i;
                    break;
                }
            }
            ans = lcm(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0; 
}