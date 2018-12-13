#include <bits/stdc++.h>
#define endl '\n';
#define D(s) cout<< s << endl;
using namespace std;

typedef vector<long long> vll;

struct shop{
    int l, s, c;
    shop(){}
    bool operator<(shop other)const{
        return l > other.l;
    }
};

const long long mmax = 2*1e9;
vll segtree;
vll dp;

void update(int pos, int l, int r, int idx, long long value){
    if(idx < l || idx > r)return;
    if(l == r && l == idx){
        dp[l] = value;
        segtree[pos] = dp[l];
    }
    else{
        int mid = (l + r)/2;
        update(pos*2, l , mid, idx, value);
        update(pos*2 + 1, mid + 1, r, idx, value);
        segtree[pos] = min(segtree[pos*2],segtree[pos*2+1]);
    }
}

long long query(int pos, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return segtree[pos];
    }
    if(qr < l || ql > r)return mmax;
    int mid = (l + r)/2;
    return min(query(pos*2, l , mid, ql, qr), query(pos*2+1, mid + 1, r, ql, qr));
}

int bs(vll &a, int i, int j, long long value){
    if(j - i == 1)return i;
    int mid = (i + j)/2;
    if(value < a[mid])return bs(a, i, mid, value);
    else if(value >= a[mid])return bs(a, mid, j, value);

}

long long solution(vll &v, vector<shop> &shops, vll &p){
    sort(shops.begin(), shops.end());
    update(1, 0, dp.size()-1 , dp.size() - 1, 0);

    for(shop i: shops){
        if(v[i.l - 1] <= i.s){
            int r = bs(p, -1, p.size(), p[i.l - 1] + i.s);
            long long mmin = query(1, 0, dp.size() - 1, i.l, r);
            if(i.c + mmin < dp[i.l-1])
                update(1, 0, dp.size()-1 , i.l-1, i.c + mmin);
        }
    }

    if(dp[0] < mmax)return dp[0];
    else return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vll v(n);
    vll p(n + 1, 0);
    vector<shop> shops(m);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> shops[i].l >> shops[i].s >> shops[i].c;
    }
    for(int i = 1; i - 1 < n ; i++){
        p[i] = v[i - 1] + p[i - 1];
    }
    dp.assign(n + 1, mmax);
    segtree.assign(4*(n + 1),mmax);
    dp[dp.size()-1] = 0;
    cout << solution(v,shops,p) << endl;
    return 0;
}