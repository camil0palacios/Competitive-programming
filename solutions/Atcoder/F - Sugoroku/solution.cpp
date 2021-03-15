#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9 + 5;
const int MXN = 1e5 + 5;
int n, m;
string s;
int dp[MXN], to[MXN];

struct Queue {
    Queue(){}
    struct node {
        int val, idx, mn, midx;
        node() {}
        node(int val, int idx, int mn, int midx): val(val), idx(idx), mn(mn), midx(midx) {}
    }; 
    stack<node> s1, s2;
    int size() {
        return s1.size() + s2.size();
    }
    bool empty() {
        return size() == 0;
    }
    void push(int val, int idx) {
        if(s1.empty()) {
            s1.push(node(val, idx, val, idx));
        } else {
            if(val < s1.top().mn) {
                s1.push(node(val, idx, val, idx));
            }
            else if(val == s1.top().mn) {
                s1.push(node(val, idx, val, min(idx, s1.top().midx)));
            } else {
                s1.push(node(val, idx, s1.top().mn, s1.top().midx));
            }
        }
    }
    void pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                int val = s1.top().val;
                int idx = s1.top().idx;
                s1.pop();
                if(s2.empty()) {
                    s2.push(node(val, idx, val, idx));
                } else {
                    if(val < s2.top().mn) {
                        s2.push(node(val, idx, val, idx));
                    }
                    else if(val == s2.top().mn) {
                        s2.push(node(val, idx, val, min(idx, s2.top().midx)));
                    } else {
                        s2.push(node(val, idx, s2.top().mn, s2.top().midx));
                    }
                }
            }
        }
        s2.pop();
    }
    pair<int,int> getMin() {
        auto a = make_pair(INF, INF), b = make_pair(INF, INF);
        if(!s1.empty() && !s2.empty()) {
            a = make_pair(s1.top().mn, s1.top().midx);
            b = make_pair(s2.top().mn, s2.top().midx);
            return min(a, b);
        }
        if(!s1.empty()) return make_pair(s1.top().mn, s1.top().midx);
        return make_pair(s2.top().mn, s2.top().midx);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> s;
    for(int i = 0; i <= n; i++) dp[i] = INF;
    // dp[i] = min(dp[i + j]) + 1  i < j <= i + x
    Queue q;
    queue<int> idx;
    dp[n] = 0;
    to[n] = n + 1;
    q.push(dp[n], n);
    idx.push(n);
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') continue;
        while(!idx.empty() && idx.front() > i + m) {
            q.pop();
            idx.pop();
        }
        if(!q.empty()) {
            auto p = q.getMin();
            dp[i] = p.first + 1;
            to[i] = p.second;
            q.push(dp[i], i);
            idx.push(i);
        }
    }
    if(dp[0] < INF) {
        int pos = 0;
        while(pos < n) {
            if(pos != 0) cout << ' ';
            cout << to[pos] - pos;
            pos = to[pos];
        } 
    } else {
        cout << -1 << endl;
    }
    return 0;
}