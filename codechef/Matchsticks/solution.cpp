#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
const int LG = 18;
int n, q, a[MAXN];
int stmax[MAXN][LG], stmin[MAXN][LG], logg[MAXN];

void build(){
    logg[1] = 0;
    for (int i = 2; i < n; i++){
        logg[i] = logg[i/2] + 1;
    }
    for(int i = 0; i < n; i++){
        stmax[i][0] = stmin[i][0] = a[i];
    }
    for(int lg = 1; lg < LG; lg++){
        for(int i = 0; i + (1 << lg) <= n; i++){
            stmax[i][lg] = max(stmax[i][lg - 1], stmax[i + (1 << (lg - 1))][lg - 1]);
            stmin[i][lg] = min(stmin[i][lg - 1], stmin[i + (1 << (lg - 1))][lg - 1]);
        }
    }
}

int queryMin(int l, int r){
    int lg = logg[r - l + 1];
    return min(stmin[l][lg], stmin[r - (1 << lg) + 1][lg]);
}

int queryMax(int l, int r){
    int lg = logg[r - l + 1];
    return max(stmax[l][lg], stmax[r - (1 << lg) + 1][lg]);
}

// int st[MAXN * 4][2];
// const int INF = 1e9;

// void build(int p, int l, int r){
//     if(l == r){
//         st[p][0] = st[p][1] = a[l];
//     }else{
//         int mid = (l + r) >> 1, left = p << 1, right = left + 1;
//         build(left, l, mid);
//         build(right, mid + 1, r);
//         st[p][0] = min(st[left][0], st[right][0]);
//         st[p][1] = max(st[left][1], st[right][1]);
//     }
// } 

// int queryMin(int p, int l, int r, int ql, int qr){
//     if(qr < l || r < ql)return INF;
//     if(ql <= l && r <= qr)return st[p][0];
//     int mid = (l + r) >> 1, left = p << 1, right = left + 1;
//     return min(queryMin(left, l, mid, ql, qr), queryMin(right, mid + 1, r, ql, qr));
// }

// int queryMax(int p, int l, int r, int ql, int qr){
//     if(qr < l || r < ql)return -INF;
//     if(ql <= l && r <= qr)return st[p][1];
//     int mid = (l + r) >> 1, left = p << 1, right = left + 1;
//     return max(queryMax(left, l, mid, ql, qr), queryMax(right, mid + 1, r, ql, qr));
// }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(1);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build();
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        double lf = -1e9, rg = -1e9;
        if(l > 0)lf = max(lf, (double)queryMax(0, l - 1));
        if(r < n - 1)rg = max(rg, (double)queryMax(r + 1, n - 1));
        double x = max(lf, rg);
        double y = queryMax(l, r);
        double mn = queryMin(l, r);
        double ans = mn + max(x, (y - mn) / 2.0);
        cout << ans << endl;
    }
    return 0;
}