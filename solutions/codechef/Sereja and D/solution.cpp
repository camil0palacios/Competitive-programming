#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
const int LG = 17;
const int INF = 1e9;
int n, d, t, q;
int a[MAXN];
int st[MAXN][LG], logg[MAXN];
int R;

void build(){
    logg[1] = 0;
    for(int i = 2; i < n; i++){
        logg[i] = logg[i / 2] + 1;
    }
    for(int i = 0; i < n - 1; i++){
        st[i][0] = a[i + 1] - a[i];
    }
    for(int p = 1; p < LG; p++){
        for(int i = 0; i + (1 << p) - 1 < n - 1; i++){
            st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
        }
    }
}

int findR(int x){
    int l = 0, r = n;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(a[mid] <= x) l = mid;
        else r = mid;    
    }
    return l;
}

bool query(int x){
    int l = x, r = R - 1;
    int j = logg[r - l + 1];
    int mx = max(st[l][j], st[r - (1 << j) + 1][j]);
    return mx <= d;
}

int findL(){
    int l = -1, r = R;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(query(mid)) r = mid;
        else l = mid;
    }
    return r + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    a[n + 1] = INF;
    build();
    cin >> q;
    while(q--){
        cin >> t >> d;
        R = findR(t);
        cout << findL() << endl;
    }
    return 0;
}