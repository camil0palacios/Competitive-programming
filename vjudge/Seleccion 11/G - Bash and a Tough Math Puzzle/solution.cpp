#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 5e5 + 10;
int a[MAXN];
int st[MAXN * 4];

int gcd(int x, int y){
    return y ? gcd(y, x % y) : x;
}

void build(int p, int l, int r){
    if(l == r){
        st[p] = a[l];
    }else{
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        build(left, l, mid);
        build(right, mid + 1, r);
        st[p] = gcd(st[left], st[right]);
    }
}

void update(int p, int l, int r, int idx, int val){
    if(idx < l || r < idx)return;
    if(l == r){
        st[p] = val;
    }else{
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        update(left, l, mid, idx, val);
        update(right, mid + 1, r, idx, val);
        st[p] = gcd(st[left], st[right]);
    }
}

int query(int p, int l, int r, int ql, int qr, int x){
    if(qr < l || r < ql)return 0;
    if(ql <= l && r <= qr){
        if(st[p] % x == 0)return 0;
        else{
            int ans = 0;
            while(l < r){
                int mid = (l + r) >> 1, left = p << 1, right = left + 1;
                if(st[left] % x != 0){
                    if(st[right] % x != 0){
                        ans += 2;
                        break;
                    }
                    r = mid;
                    p = left;
                }else{
                    l = mid + 1;
                    p = right;
                }
            }
            ans++;
            return ans;
        }
    }else{
        int mid = (l + r) >> 1, left = p << 1, right = left + 1;
        int a = query(left, l, mid, ql, qr, x);
        int b = query(right, mid + 1, r, ql, qr, x);
        return a + b;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n - 1);
    cin >> q;
    while(q--){
        int c, l, r, x;
        cin >> c >> l >> r;
        l--;
        if(c == 1){
            cin >> x;
            r--;
            int ans = query(1, 0, n - 1, l, r, x);
            cout << (ans <= 1 ? "YES" : "NO") << endl;
        }else{ 
            update(1, 0, n - 1, l, r);
        }
    }
    return 0;
}