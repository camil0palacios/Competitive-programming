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

vector<vector<string>> ans;

struct Node {
    map<int,Node*> m;
    Node *p;
    Node(): p(nullptr) { m[0] = nullptr; }
    void dfs(vector<string> & v) {
        for(auto & pr : m) {
            if(!pr.ft) continue;
            v.eb(to_string(pr.ft));
            ans.eb(v);
            v.eb(string(1, '.'));
            pr.sd->dfs(v);
            v.pop_back();
            v.pop_back();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Node *r, *cur;
        r = new Node();
        cur = r;
        fori(i,0,n) {
            int a;
            cin >> a;
            while(cur != r && (cur->m.count(a) || !cur->m.count(a-1))) cur = cur->p;
            auto tmp = new Node();
            cur->m[a] = tmp;
            tmp->p = cur;
            cur = cur->m[a];
        }
        vector<string> tmp;
        ans.clear();
        r->dfs(tmp);
        for(auto & v : ans) {
            for(auto & t : v) cout << t;
            cout << endl;
        }
    }
    return 0; 
}