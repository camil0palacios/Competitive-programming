#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

typedef pair<ll,ll> pll;
const ll INF = 1e18;

struct MaxQueue {
    stack<pll> s1, s2;
    MaxQueue() {}
    int size() {
        return s1.size() + s2.size();
    }
    bool empty() {
        return size() == 0;
    }
    void push(ll val) {
        ll mx = s1.empty() ? val : max(val, s1.top().second);
        s1.push({val, mx});    
    }
    void pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                ll elem = s1.top().first;
                s1.pop();
                ll mx = s2.empty() ? elem : max(elem, s2.top().second);
                s2.push({elem, mx});
            }
        }
        s2.pop();
    } 
    ll getMax() {
        if(!s1.empty() && !s2.empty()) 
            return max(s1.top().second, s2.top().second);
        if(!s1.empty()) return s1.top().second;
        if(!s2.empty()) return s2.top().second;
        else return -INF;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n / k > x) {
        cout << -1 << endl;
        return 0; 
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -INF));
    vector<MaxQueue> q(x + 1); 
    vector<queue<int>> pos(x + 1);
    for(int i = n - k + 1; i < n; i++) {
        dp[i][x] = 0;
    }
    pos[x].push(n);
    q[x].push(0LL);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = x; j >= 0; j--) {
            while(!q[j].empty() && pos[j].front() > i + k) {
                q[j].pop();
                pos[j].pop();
            }
        }
        for(int j = 0; j < x; j++) {
            if(!q[j + 1].empty()) {
                dp[i][j] = max(dp[i][j], q[j + 1].getMax() + a[i]);
                q[j].push(dp[i][j]);
                pos[j].push(i);
            }
        }
    }
    ll mx = -INF;
    for(int i = 0; i < k; i++) {
        mx = max(mx, dp[i][0]);
    }
    cout << (mx > 0 ? mx : -1) << endl;
    return 0;
}