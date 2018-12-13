#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;

struct node{
    int x, y, q, idx;
    node(int _x, int _y, int _q, int _idx): x(_x), y(_y), q(_q), idx(_idx){}
    bool operator <(node other)const{
        if(x == other.x)return q < other.q;
        else return x < other.x;
    } 
};

class Segtree{
    private:
        vi v, a;
        int n;

        void build(int pos, int l, int r){
            if(l > r)return;
            if(l == r){
                v[pos] += a[l];
            }
            int mid = (l + r)/2;
            build(pos*2, l, mid);
            build(pos*2+1, mid + 1, r);
        }

        void update(int pos, int l, int r, int idx, int delta){
            if(l == r && l == idx){
                a[l] = delta;
                v[pos] = a[l];
            }
            else{
                if(idx < l || idx > r)return;
                int mid = (l + r)/2;
                update(pos*2, l, mid, idx, delta);
                update(pos*2+1, mid + 1, r, idx, delta);
                v[pos] = v[pos*2] + v[pos*2+1];
            }
        }

        int query(int pos, int l, int r, int ql, int qr){
            if(qr < l || ql > r)return 0;
            if(ql <= l && qr >= r)return v[pos];
            int mid = (l + r)/2;
            return query(pos*2, l, mid, ql, qr) + query(pos*2+1, mid + 1, r, ql, qr);
        }

    public:

        Segtree(){
            n = 200005;
            a.assign(n, 0);
            v.assign(4*n, 0);
        }

        void update(int i, int delta){
            update(1, 0, n - 1, i, delta);
        }

        int query(int i){
            return query(1, 0, n - 1, i, n - 1);
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p, v, x, y;
    cin >> p >> v;
    vector<node> a;
    set<int> sety;
    for(int i = 1; i <= p; i++){
        cin >> x >> y;
        sety.insert(y);
        a.emplace_back(node(x,y,3,i));
    }
    cin >> x >> y;
    sety.insert(y);
    int first = a.size();
    a.emplace_back(node(x,y,-1,0));
    for(int i = 1; i < v; i++){
		cin >> x >> y;
        //cout << x << " " << y << endl;
		sety.insert(y);
		a.emplace_back(node(x, y, -1, 0));
		int tam = a.size()-2;
		if(x!=a[tam].x){
			if(x<a[tam].x){
			 	a[tam+1].q = 1;
				a[tam].q = 0;
			}else{
				a[tam+1].q = 0;
				a[tam].q = 1;
			}
		}	
	}
    int last = a.size() - 1;
    if(a[first].y == a[last].y){
        if(a[first].x < a[last].x){
            a[first].q = 1;
            a[last].q = 0;
        }
        else{
            a[first].q = 0;
            a[last].q = 1;
        }
    }
    map<int,int> mii;
    int k = 1;
    for(auto i: sety){
        mii[i] = k;
        k++;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    Segtree st;
    for(auto i : a){
        if(i.q == 0){
            st.update(mii[i.y],0);
            //cout << "update 0 " << st.query(0) << endl;
        }
        else if(i.q == 1){
            st.update(mii[i.y],1);
            //cout << "update 1 " << st.query(0) << endl;
        }
        else if(st.query(mii[i.y]) % 2 == 0){
            //cout << "query " << st.query(mii[i.y]) << endl;
            ans += i.idx;
        }
    }
    cout << ans << endl;
    return 0;
}