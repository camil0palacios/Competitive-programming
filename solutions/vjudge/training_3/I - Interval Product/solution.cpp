#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int const nmax = 1e5 + 5;
int sgt[4*nmax];

void update(int pos, int l, int r, int idx, int val){
    if(idx < l || r < idx)return;
    if(l == r){
        sgt[pos] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update((pos << 1), l, mid, idx, val);
    update((pos << 1) + 1, mid + 1, r, idx, val);
    sgt[pos] = sgt[(pos << 1)] * sgt[(pos << 1) + 1];
}

int query(int pos, int l, int r, int i, int j){
    if(j < l || r < i)return 1;
    if(i <= l && r <= j){
        return sgt[pos];
    }
    int mid = (l + r) >> 1;
    return query((pos << 1), l, mid, i, j) * query((pos << 1) + 1, mid + 1, r, i, j);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    while(cin >> n >> q){
        memset(sgt, 0, sizeof sgt);
        int val;
        for(int i = 0; i < n; i++){
            cin >> val;
            int x = 0;
            if(val > 0)x = 1;
            if(val < 0)x = -1;
            update(1,1,n,i+1,x);
        }
        char c;
        int a, b;
        for(int i = 0; i < q; i++){
            cin >> c >> a >> b;
            if(c == 'C'){
                int x = 0;
                if(b > 0)x = 1;
                if(b < 0)x = -1;
                update(1,1,n,a,x);
            }else{
                int ans = query(1,1,n,a,b);
                if(ans == 0)cout << 0;
                else if(ans > 0)cout << '+';
                else cout << '-';
            } 
        }
        cout << endl;
    }
    return 0;
}