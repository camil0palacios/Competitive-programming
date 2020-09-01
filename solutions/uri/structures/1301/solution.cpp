#include <bits/stdc++.h>
#define end '\n'
using namespace std;

vector<int> segtree;

void build(vector<int> &a, int tl, int tr, int pos){
  if(tl == tr){
    if(a[tl] == 0)segtree[pos] = 0;
    else segtree[pos] = (a[tl] > 0 ? 1 : -1);
  }
  else{
    int mid = (tl + tr)/2;
    build(a, tl, mid, 2*pos);
    build(a, mid + 1, tr, 2*pos + 1);
    segtree[pos] = segtree[2*pos]*segtree[2*pos + 1];
  }
}

int update(int pos, int l, int r, int val, int pos1){
  if(l == r && l == pos1){
    if(val == 0)segtree[pos] = 0;
    else segtree[pos] = (val > 0 ? 1 : -1);
  }
  else if(l <= pos1 && pos1 <= r){
    int mid = (l + r)/2;
    update(pos*2, l, mid, val, pos1);
    update(pos*2 + 1, mid + 1, r, val, pos1);
    segtree[pos] = segtree[pos*2]*segtree[pos*2 + 1];
  }
  else return segtree[pos];
}

int query(int pos, int l, int r, const int &i,const int &j){
  if(i <= l && j >= r)return segtree[pos];
  if(i > r || j < l)return 1;
  int tm = (l + r)/2;
  return query(pos*2, l, tm, i, j) * query(pos*2 + 1, tm + 1, r, i, j);
}

int main(){

  int n, m;
  while(cin >> n >> m){
    vector<int> v(n);
    for(auto &i : v)cin>>i;
    segtree.assign(4*n,0);
    build(v, 0, n - 1, 1);
    while(m--){
      int b, c;
      char a;
      cin >> a >> b >> c;
      if(a == 'C'){
        v[b - 1] = c;
        update(1, 0, n - 1, c, b - 1);
      }
      else if(a == 'P'){
        int ans = query(1, 0,  n - 1, b - 1, c - 1);
        if(ans > 0)cout << "+";
        else if(ans < 0)cout << "-";
        else cout << "0";
      }
    }
    cout << endl;
  }
  return 0;
}
