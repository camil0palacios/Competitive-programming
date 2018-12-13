#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
ll pp;

int extended_euclidean(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

class SegmenTree{
    private:
        vector<long long> t, a;
        void update(int pos, int l, int r, int idx, ll val){
            if(l == r && l == idx){
                t[pos] = ((a[idx]%pp)*(val%pp))%pp;
            }
            else{
                if(idx < l || idx > r)return;
                int mid = (l + r)/2;
                update(pos*2, l, mid, idx, val);
                update(pos*2+1, mid + 1, r, idx, val);
                t[pos] = (t[pos*2]%pp + t[pos*2 + 1]%pp)% pp;
            }
        }
        ll query(int pos, int l, int r, int ql, int qr){
            if(qr < l || ql > r)return 0;
            if(ql <= l && r <= qr)return t[pos];
            int mid = (l + r)/2;
            ll left = query(pos*2, l, mid, ql, qr);
            ll right = query(pos*2 + 1, mid+1, r, ql, qr);
            return (left%pp + right%pp)%pp;
        }
    public:
        SegmenTree(ll B, int L){
            a.assign(L,0);
            ll x = 1;
            for(int i = L - 1; i > -1; i--){
                a[i] = x;
                x = (x%pp * B%pp)%pp;
            }
            t.assign(a.size()*4,0);
        }
        void update(int idx, ll val){
            update(1, 0, a.size() - 1, idx, val);
        }
        ll query(int ql, int qr){
            int x, y;
            int g = extended_euclidean(a[qr], pp, x, y);
            x = (x % pp + pp) % pp;
            return (query(1, 0, a.size()-1, ql, qr)*x)%pp;
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long B, P;
    int L, N;
    while(cin >> B >> P >> L >> N, B, P, L, N){
        char c; 
        long long i, j;
        pp = P;
        SegmenTree segtree(B, L);
        while(N--){
            cin >> c >> i >> j;
            if(c == 'E')segtree.update(i-1,j);
            else cout << segtree.query(i-1,j-1) << endl;
        }
        cout << "-" << endl;
    }

    return 0;
}