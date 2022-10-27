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
int a[N];
int ans[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        multiset<int> s;
        map<int, vii> q;
        fori(i,0,n) cin >> a[i], s.insert(a[i]);
        fori(i,0,m) {
            int x, y;
            cin >> x >> y;
            q[x].emplace_back(y, i);
            ans[i] = 0;
        }
        fori(i,0,n) {
            int x = a[i];
            while(!q[x].empty()) {
                auto p = q[x].back();
                ans[p.sd] = s.find(p.ft) != s.end();
                q[x].pop_back();
            }
            s.erase(s.find(x));
        }
        fori(i,0,m) cout << (ans[i] ? "YES" : "NO") << endl;
        
    }
    return 0; 
}