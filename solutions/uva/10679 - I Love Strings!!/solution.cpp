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
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;

int to_int(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26; 
}

const int Mxe = 53;

struct AhoCorasick {
    struct Node {   
        vi edge, id;
        Node() {}
        Node(int n) { edge.assign(n, -1); }
    };
    vector<Node> t; 
    vi fail;
    AhoCorasick() { t.eb(Mxe), fail.eb(0); }
    void add(string & s, int id) {
        int cur = 0;
        for(auto & c : s) {
            int x = to_int(c);
            if(t[cur].edge[x] == -1) {
                t[cur].edge[x] = sz(t);
                t.eb(Mxe);
                fail.eb(0);
            }
            cur = t[cur].edge[x];
        }
        t[cur].id.eb(id);
    }
    void build() {
        fori(i, 0, Mxe) {
            if(t[0].edge[i] == -1) {
                t[0].edge[i] = 0;
            }
        }
        queue<int> q;
        fori(i, 0, Mxe) {
            if(t[0].edge[i] != 0) {
                q.push(t[0].edge[i]);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            fori(i, 0, Mxe) {
                if(t[u].edge[i] != -1) {
                    int v = t[u].edge[i];
                    q.push(v);
                    int tmp = fail[u];
                    while(t[tmp].edge[i] == -1) {
                        tmp = fail[tmp];
                    }
                    fail[v] = t[tmp].edge[i];
                }
            }
        }
    }
    void match(string & text, vb & ans) {
        int cur = 0;
        for(auto & c : text) {
            int x = to_int(c);
            while(t[cur].edge[x] == -1) cur = fail[cur];
            cur = t[cur].edge[x];
            for(auto & i : t[cur].id) {
                ans[i] = 1;
            }
        }
    }
};

void solve() {
    string t;
    int q;
    cin >> t >> q;
    AhoCorasick aho;
    for(int i = 0; i < q; i++) {
        string p;
        cin >> p;
        aho.add(p, i);
    }
    aho.build();
    vb ans(q, 0);
    aho.match(t, ans);
    fori(i,0,q) {
        cout << (ans[i] ? 'y' : 'n') << endl;   
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}