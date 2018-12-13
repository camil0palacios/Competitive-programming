#include <bits/stdc++.h>
using namespace std;

struct rich{
    int x, y;
    rich(){}
    bool operator<(rich other)const{
        if(x == other.x)return y > other.y;
        else return x < other.x;
    }
};

struct Node{
    Node *l, *r;
    long long ans;
    Node(): ans(0), r(nullptr), l(nullptr){}
};

typedef Node* cnode;
typedef long long ll;

void modify(cnode cur){
    long long mmax1 = 0, mmax2 = 0;
    if(cur -> l) mmax1 = cur -> l -> ans;
    if(cur -> r) mmax2 = cur -> r -> ans;
    cur -> ans = max(mmax1,mmax2);
}

cnode update(cnode cur, ll l, ll r, ll idx, ll value){
    if(!cur)cur = new Node();
    if(idx < l || idx > r)return cur;
    if(l == r && l == idx){
        cur -> ans = value;
        return cur;
    }
    ll mid = floor((l + r)/2.0);
    cur -> l = update(cur -> l, l, mid, idx, value);
    cur -> r = update(cur -> r, mid + 1, r, idx, value);
    
    modify(cur);
    
    return cur;
}

ll query(cnode cur, ll l, ll r, ll ql, ll qr){
    if(!cur)return 0;
    if(qr < l || ql > r)return 0;
    if(ql <= l && r <= qr)return cur -> ans;
    ll mid = floor((l + r)/2.0);
    return max(query(cur -> l, l, mid, ql, qr), query(cur -> r, mid + 1, r, ql, qr));
}

ll MAX_VAL = 4*1e9;
ll VAL = 1e9;

ll solution(map<rich,ll> &m){
    cnode root = NULL;
    map<int,ll> dp;
    dp[0] = 0;
    for(auto i : m){
        ll mmax = query(root, 0, VAL, 0, i.first.y - 1);
        if(mmax + i.second > dp[i.first.y]){
            dp[i.first.y] = mmax + i.second;
            root = update(root, 0, VAL, i.first.y, dp[i.first.y]);
        }
    }
    return query(root, 0, VAL, 0, VAL);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, b, f, d;
    cin >> n;
    map<rich,ll> m;
    for(int i = 0; i < n; i++){
        rich tmp;
        cin >> tmp.x >> tmp.y >> d;
        if(m.count(tmp) == 0)m[tmp] = d;
        else m[tmp] += d;
    }
    cout << solution(m) << endl;
    return 0;
}