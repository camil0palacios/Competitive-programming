#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node{
    Node *l, *r;
    long long sum;
    Node():l(nullptr),r(nullptr),sum(0){}
};

typedef Node* cnode;

void modify(cnode cur){
    long long ans = 0;
    if(cur -> l) ans += cur -> l -> sum;
    if(cur -> r) ans += cur -> r -> sum;
    cur -> sum = ans; 
}

Node* update(cnode cur, int l, int r, int idx, int value){
    if(cur == NULL)cur = new Node();
    if(idx < l || idx > r)return cur;
    if(l == r && l == idx){
        cur -> sum = value;
        return cur;
    }
    else{
        int mid = floor((l + r)/2.0);
        cur -> l = update(cur -> l, l, mid, idx, value);
        cur -> r = update(cur -> r, mid + 1, r, idx, value);
        modify(cur);
        return cur;
    }
}

long long query(cnode cur, int l, int r, int ql, int qr){
    //if(l > r)return  0;
    if(!cur)return 0;
    if(qr < l || ql > r)return 0;
    if(ql <= l && r <= qr)return cur -> sum;
    int mid = floor((l + r)/2.0);
    long long left = query(cur -> l, l, mid, ql, qr);
    long long right = query(cur -> r, mid + 1, r, ql, qr);
    return left + right;
}

struct nodo{
    int x, y, q, idx;
    nodo(int _x, int _y, int _q, int _idx): x(_x), y(_y), q(_q), idx(_idx){}
    bool operator<(nodo other)const{
        if(x == other.x)return q < other.q;
        else return x < other.x;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p, v, x, y;
    cin >> p >> v;
    vector<nodo> a;
    for(int i = 1; i <= p; i++){
        cin >> x >> y;
        //cout << x << " " << y << endl;
        a.emplace_back(nodo(x,y,2,i));
    }
    cin >> x >> y;
    a.emplace_back(nodo(x,y,0,0));
    int first = a.size() - 1;
    for(int i = 1 ; i < v; i++){
        cin >> x >> y;
        //cout << x << " " << y << endl;
        a.emplace_back(nodo(x,y,0,0));
        int tmp = a.size() - 2;
        if( x != a[tmp].x){
            if(x < a[tmp].x){
                a[tmp + 1].q = 1;
                a[tmp].q = 0;
            }
            else{
                a[tmp + 1].q = 0;
                a[tmp].q = 1;
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
    sort(a.begin(), a.end());
    cnode root = NULL;
    int MAX_VALUE = 1000000000;
    long long ans = 0;
    for(auto i : a){
        if(i.q == 0){
            root = update(root, - MAX_VALUE, MAX_VALUE, i.y, 0);
            //cout << "update 0 " << query(root,-MAX_VALUE, MAX_VALUE, 0, MAX_VALUE) << endl;
        }
        else if(i.q == 1){
            root = update(root, - MAX_VALUE, MAX_VALUE, i.y, 1);
            //cout << "update 1 " << query(root,-MAX_VALUE, MAX_VALUE, 0, MAX_VALUE) << endl;
        }
        else if(query(root,-MAX_VALUE, MAX_VALUE, i.y, MAX_VALUE)%2 == 0){
            ans += i.idx;
        }
    }
    cout << ans << endl;
    return 0;
}