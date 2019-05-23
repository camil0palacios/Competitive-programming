#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1000000007;
const int NM = 1e6 + 5;
vector<pair<ll,int>> a;
ll dp[NM];

void update(int pos, int l, int r, int idx, int val){
    if(idx < l || r < idx || l > r)return;
    if(l == r){
        dp[pos] = (dp[pos] + val) % mod;
        return;
    }
    int mid = (l+r) >> 1;
    update((pos << 1), l, mid, idx, val);
    update((pos << 1) + 1, mid+1, r, idx, val);
    dp[pos] = (dp[(pos<<1)] + dp[(pos<<1)+1]) % mod;
}

ll query(int pos, int l, int r, int i, int j){
    if(j < l || r < i || l > r)return 0;
    if(i <= l && r <= j){
        return dp[pos];
    }
    int mid = (l+r) >> 1;
    ll q1 = query((pos << 1),l,mid,i,j) % mod;
    ll q2 = query((pos << 1)+1,mid+1,r,i,j) % mod;
    return (q1 + q2) % mod;
}

void solve(){
    int n;
    cin >> n;
    a.clear();
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end(),[&](pair<ll,int> p1, pair<ll,int> p2){
        if(p1.first < p2.first)return true;
        else if(p1.first == p2.first && p1.second > p2.second)return true;
        else return false;
    });
    memset(dp, 0, sizeof dp);
    update(1,0,n,0,1);
    for(int i = 0; i < n; i++){
        int idx = a[i].second;
        int sum = query(1,0,n,0,idx-1);
        update(1,0,n,idx,sum);
    }
    ll ans = query(1,0,n-1,1,n);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}