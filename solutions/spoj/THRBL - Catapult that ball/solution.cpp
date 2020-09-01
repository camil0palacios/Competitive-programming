#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 10;
const int K = 20;
int n, q, a[MAXN];
int st[MAXN][K], Log[MAXN];

void build(){
    Log[1] = 0;
    for(int i = 2; i < n; i++){
        Log[i] = Log[i / 2] + 1;
    }
    for(int i = 0; i < n; i++){
        st[i][0] = a[i];
    }
    for(int j = 1; j < K; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int j = Log[r - l + 1];
    return max(st[l][j], st[r - (1 << j) + 1][j]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build();
    int ans = 0;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        ans += query(l, r - 1) <= a[l];
    }
    cout << ans << endl;
    return 0;
}