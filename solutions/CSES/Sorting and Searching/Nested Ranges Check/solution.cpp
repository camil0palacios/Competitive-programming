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

const int Mxn = 2e5 + 5;
ii r[Mxn];
int ans[Mxn][2];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vii p;
    fore(i,1,n) {
        cin >> r[i].ft >> r[i].sd;
        p.eb(r[i].ft, -i);
        p.eb(r[i].sd, i);
    }
    sort(all(p), [&](ii a, ii b) {
        if(a.ft == b.ft) {
            if(a.sd > 0 && b.sd > 0) return r[a.sd].ft > r[b.sd].ft;
            return a.sd < b.sd;
        }
        return a.ft < b.ft;
    });
    multiset<int, greater<int>> op;
    multiset<int> cl;
    for(auto & pt : p) {
        int x = pt.ft, i = pt.sd;
        if(i < 0) op.insert(x);
        else {
            op.erase(op.find(r[i].ft));
            auto it = op.lower_bound(r[i].ft);
            if(it != op.end()) ans[i][1] = 1;
            it = cl.lower_bound(r[i].ft);
            if(it != cl.end()) ans[i][0] = 1;
            cl.insert(r[i].ft);
        }
    }
    fore(i,1,n) {
        if(i != 1) cout << ' '; 
        cout << ans[i][0];
    }
    cout << endl;
    fore(i,1,n) {
        if(i != 1) cout << ' ';
        cout << ans[i][1];
    }
    cout << endl;
    return 0;
}