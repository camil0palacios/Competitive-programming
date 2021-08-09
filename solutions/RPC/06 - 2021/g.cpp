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

struct Dsu {
    vi p, tm;
    Dsu(){}
    void build(int n) { tm.resize(n), p.resize(n); fori(i,0,n) p[i] = i, tm[i] = 1; }
    int find(int a){ return a == p[a] ? a : p[a] = find(p[a]); }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) {
            tm[a] += tm[b];
            p[b] = a;
        }
    }
};

int dx[8] = {1, 0, -1, 0, 1,  1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1,  1, -1};
int bl[8] = {0, 1, 0,  1, 2,  3,  3,  2};

map<int, int> st;
set<ii> s[2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int h, w, k;
    cin >> h >> w >> k;
    int win = -1, tr_win = 0, t = 0;
    Dsu ds[2][4];
    fori(i,0,2) fori(j,0,4) ds[i][j].build(h*w);
    fori(i,0,h*w) {
        int r, c;
        cin >> c;
        c--;
        r = st[c]++;
        fori(j,0,8) {
            int mx = r + dx[j], my = c + dy[j];
            if(mx >= 0 && mx < h && my >= 0 && my < w && s[t].count({mx, my})) {
                ds[t][bl[j]].join(r*w + c, mx*w + my);
            }
        }
        fori(j,0,4) {
            if(ds[t][j].tm[ds[t][j].find(r*w + c)] >= k && win == -1) {
                win = !t ? 1 : 2;
                tr_win = i+1;
            }
        }
        s[t].insert({r, c});
        t ^= 1;
    }
    if(win == 1) cout << "A" << ' ' <<  tr_win << endl;
    else if(win == 2) cout << "B" << ' ' << tr_win << endl;
    else cout << "D" << endl;
    return 0;
}