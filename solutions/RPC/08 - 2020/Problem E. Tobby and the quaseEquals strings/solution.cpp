#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXCHAR = 26;
int n, q, L;
int ans = 0;

struct Node {
    int cnt;
    Node * edge[MXCHAR];
    Node(): cnt(0) {
        for(int i = 0; i < MXCHAR; i++) edge[i] = NULL;
    }
};

void insert(Node * root, string s) {
    Node * u = root;
    for(auto & c : s) {
        int nxt = c - 'a';
        if(u -> edge[nxt] == NULL) {
            u -> edge[nxt] = new Node();
        }
        u = u -> edge[nxt];
    }
    u -> cnt++;
}

void find(Node * u, int diff, int idx, string & s) {
    if(idx == L) {
        ans += diff == 1 ? u -> cnt : u->cnt * L;
        return;
    }
    if(diff == 1) {
        if(u -> edge[s[idx] - 'a'] != NULL) 
            find(u -> edge[s[idx]-'a'], diff, idx + 1, s);
    } else {
        for(int i = 0; i < MXCHAR; i++) {
            if(u -> edge[i] == NULL) continue;
            find(u -> edge[i], diff + (s[idx] - 'a' != i), idx + 1, s);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> q >> L) {
        Node * root = new Node();
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            insert(root, s);
        }
        for(int i = 0; i < q; i++) {
            string s; cin >> s;
            ans = 0;
            find(root, 0, 0, s);
            cout << ans << endl;
        }
    }
    return 0;
}