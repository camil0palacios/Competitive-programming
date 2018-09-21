#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

class segmenTree{
    private: vi st, A;
    int n;
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)+1;}

    void build(int p, int L, int R){
        if(L==R)
            st[p] = L;
        else{
            build(left(p)  , L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            int p1=st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2])? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int i, int j){
        if(i > R || j < L)return -1;
        if(L >= i && R <= j) return st[p];
        int p1 = rmq(left(p), L, (L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2+1, R, i, j);

        if(p1 == -1)return p2;
        if(p2 == -1)return p1;
        return (A[p1] <= A[p2])? p1 : p2;
    }

    void update(int p, int L, int R, int i){
        if(L==R)st[p]=L;
        else if(L<=i && i<=R){
            update(left(p), L, (R+L)/2, i);
            update(right(p), (R+L)/2+1, R, i);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2])? p1 : p2;
        }
    }
    public:
    segmenTree(const vi &_A){
        A = _A; n = (int)A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    segmenTree(){}

    long long rmq(int i, int j){
        return rmq(1, 0, n-1, i, j);
    }

    void update(int i, int w){A[i]+=w; update(1, 0, n-1, i);}
};

struct LCA{
  vector<int> euler, height,first;
  vector<bool> used;
  segmenTree st;
  vector<vector<int>> g;

  LCA(vector<vector<int>> &v){
    g=v;
    used.assign(g.size(),false);
    first.assign(g.size(),0);
    dfs(0,0);
    st= segmenTree(height);
  }

  void dfs(int node, int h){
    used[node]=true;
    euler.push_back(node);
    height.push_back(h);
    first[node]=euler.size()-1;
    for(auto to: g[node]){
      if(!used[to]){
        dfs(to, h+1);
        euler.push_back(node);
        height.push_back(h);
      }
    }
  }

  int query(int a, int b){
    int x=first[a], y=first[b];
    if(x>y)
      swap(x,y);
      int id  = st.rmq(x,y);
      return euler[id];
  }
};


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, tam, aux, k, q, a, b;
    cin >> n;
    for(int i=1; i<=n; i++){
      cin >> tam;
      vector<vector<int>> v(tam);
      for(int j=0; j<tam; j++){
        cin >> k;
        while(k--){
            cin >> aux;
            v[j].push_back(--aux);
        }
      }
      LCA L(v);
      cout << "Case " << i << ":\n";
      cin >> q;
      while(q--){
        cin >> a >> b;
        cout << L.query(--a,--b)+1 << '\n';
      }
    }
}
