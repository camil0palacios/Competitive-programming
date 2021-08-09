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

const int mod = 1e9 + 7;
const int Mxn = 4e5 + 5;
int a[Mxn], b[Mxn], p[Mxn];
bool vis[Mxn];

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) vis[i] = 0; 
        fore(i,1,n) cin >> a[i], p[a[i]] = i;
        fore(i,1,n) cin >> b[i];
        int cnt = 0;
        fore(i,1,n) {
            if(!vis[i]) {
                int u = i;
                do {
                    vis[u] = 1;
                    u = p[b[u]];
                } while(u != i);
                cnt++;
            }
        }
        cout << be(2ll, cnt) << endl;
    }
    return 0; 
}