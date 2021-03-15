#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vii pt(n);
    fori(i,0,n) cin >> pt[i].ft >> pt[i].sd;
    sort(all(pt), [&](ii & x, ii & y) {
        if(abs(x.ft) == abs(y.ft)) return abs(x.sd) < abs(y.sd);
        return abs(x.ft) < abs(y.ft);
    });
    vector<pair<int,pair<int,char>>> ans; 
    fori(i,0,n) {
        bool dx = pt[i].ft > 0;
        bool dy = pt[i].sd > 0;
        int x = abs(pt[i].ft), y = abs(pt[i].sd);
        if(x != 0) ans.eb(1, mp(x, (dx ? 'R' : 'L')));
        if(y != 0) ans.eb(1, mp(y, (dy ? 'U' : 'D')));
        ans.eb(2, mp(0,0));
        if(x != 0) ans.eb(1, mp(x, (dx ? 'L' : 'R')));
        if(y != 0) ans.eb(1, mp(y, (dy ? 'D' : 'U')));
        ans.eb(3, mp(0,0));
    }
    cout << sz(ans) << endl;
    for(auto & i: ans) {
        int op = i.ft;
        cout << op;
        if(op == 1) {
            int k = i.sd.ft;
            char dir = i.sd.sd;
            cout << ' ' << k << ' ' << dir;
        }
        cout << endl;
    }
    return 0; 
}