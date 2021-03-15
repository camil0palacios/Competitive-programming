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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<ii> s;
    int sx = 0, sy = 0;
    bool ok = 1;
    fori(i,0,4) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        s.insert({x1, y1});
        s.insert({x2, y2});
        bool t = 0;
        if(x1 == x2) sx++, t = 1; 
        else if(y1 == y2) sy++, t = 1;
        ok &= t;
    }
    if(!ok || sz(s) != 4 || sx != 2 || sy != 2) { cout << "NO" << endl; return 0; }
    vii pt;
    for(auto & i : s) pt.eb(i);
    int p[4] = {0, 1, 2, 3};
    do {
        vii t;
        fori(i,0,4) t.eb(pt[p[i]]);
        if(t[0].sd == t[1].sd && t[0].ft == t[2].ft && t[3].sd == t[2].sd && t[3].ft == t[1].ft &&
           t[0].ft < t[1].ft && t[0].sd < t[2].sd) {
            cout << "YES" << endl;
            return 0;
        }
    } while(next_permutation(p, p+4));
    cout << "NO" << endl;
    return 0; 
}