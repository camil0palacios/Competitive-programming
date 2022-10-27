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

const int Mxn = 3e5 + 5;
int h[Mxn];
set<ii> b[2];
int belong[Mxn];

void solve() {
    int d, n, k;
    cin >> d >> n >> k;
    vii ev;
    fore(i,1,n) {
        int s, e;
        cin >> h[i] >> s >> e;
        ev.eb(s, -i);
        ev.eb(e, i); 
    }
    ll ans = 0, sum = 0;
    b[0].clear(), b[1].clear();
    fore(i,0,n) belong[i] = -1;
    sort(all(ev));
    for(auto & e : ev) {
        int y = e.sd;
        if(y < 0) {
            y *= -1;
            if(sz(b[1]) < k) {
                b[1].insert({h[y], y});
                belong[y] = 1;
                sum += h[y];
            } else {
                auto p = *b[1].begin();
                if(p.ft < h[y]) {
                    b[0].insert(p);
                    b[1].erase(p);
                    belong[p.sd] = 0;
                    sum -= p.ft;
                    b[1].insert({h[y], y});
                    belong[y] = 1;
                    sum += h[y];
                } else {
                    b[0].insert({h[y], y});
                    belong[y] = 0;
                }
            }
        } else {
            if(belong[y]) {
                sum -= h[y];
                if(sz(b[0])) {
                    auto p = *b[0].rbegin();
                    b[0].erase(p);
                    b[1].insert(p);
                    sum += p.ft;
                    belong[p.sd] = 1;
                }
            }
            b[belong[y]].erase({h[y], y});
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}