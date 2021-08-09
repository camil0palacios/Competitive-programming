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

ll dist(int x1, int y1, int x2, int y2) {
    return 1ll*abs(x1 - x2) + abs(y1 - y2);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int dx[4] = {1, 1, n, n};
        int dy[4] = {1, m, 1, m};
        vi ans;
        ll mx = -1;
        fori(i,0,4) {
            fori(j,0,4) {
                ll s = dist(x, y, dx[i], dy[i]) + 
                    dist(dx[i], dy[i], dx[j], dy[j]) + 
                    dist(dx[j], dy[j], x, y);
                if(mx <= s) {
                    ans = {dx[i], dy[i], dx[j], dy[j]};
                    mx = s;
                }
            }
        }
        for(auto & i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0; 
}