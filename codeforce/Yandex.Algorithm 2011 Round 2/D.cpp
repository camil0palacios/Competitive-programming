#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int block_size;
int const len = 1000000;
int frec[len + 1];
long long total = 0;
vector<int> a;

void add(int i){
    total -= (long long)((long long)(frec[a[i]]*frec[a[i]])*a[i]);
    frec[a[i]]++;
    total += (long long)((long long)(frec[a[i]]*frec[a[i]])*a[i]);
}

void del(int i){
    total -= (long long)((long long)(frec[a[i]]*frec[a[i]])*a[i]);
    frec[a[i]]--;
    total += (long long)((long long)(frec[a[i]]*frec[a[i]])*a[i]);
}

struct Query{
    int l, r, idx;
    Query(){}
    Query(int _l, int _r, int _idx){
        l = _l;
        r = _r;
        idx = _idx;
    }
    bool operator<(Query other){
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
    }
};

vector<long long> mo_s_algorithm(vector<Query> queries){
    vector<long long> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
    for(auto q : queries){
        while(cur_l > q.l){
            cur_l--;
            add(cur_l);
        }
        while(cur_r < q.r){
            cur_r++;
            add(cur_r);
        }
        while(cur_l < q.l){
            del(cur_l);
            cur_l++;
        }
        while(cur_r > q.r){
            del(cur_r);
            cur_r--;
        }
        answers[q.idx] = total;
    }
    return answers;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    a.assign(n,0);
    for(auto &i : a)cin >> i;
    block_size = (int)sqrt(n + .0) + 1; 
    vector<Query> queries(q);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        queries[i] = Query(--l, --r, i);
    }
    for(auto &i: mo_s_algorithm(queries)){
        cout << i << endl;
    }
    return 0;
}