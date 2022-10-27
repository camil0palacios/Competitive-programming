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
vii bit[32];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        fori(i,0,31) bit[i].clear();
        fori(i,0,n) {
            fori(j,0,31) {
                if((a[i] >> j) & 1) bit[j].push_back(mp(a[i], i));
            }
        }
        int x = 0;
        vi ans;
        set<ii> s;
        forr(i,30,0) {
            if((x >> i) & 1) continue;
            int y = 0, j = -1;
            for(auto [p, idx] : bit[i]) {
                if((x | y) < (x | p)) {
                    y = p;
                    j = idx;
                }
            }
            if(j != -1) {
                x |= y;
                ans.emplace_back(a[j]);
                s.insert(mp(a[j], j));
            }
        }
        fori(i,0,n) {
            if(!s.count(mp(a[i], i))) {
                ans.emplace_back(a[i]);
            }
        }
        for(auto i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0; 
}
