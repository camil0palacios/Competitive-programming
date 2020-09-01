#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int block_size;
int const len = 1<<20;
vector<int> p;

struct DS{
    int k;
    long long total;
    vector<int> frec;
    DS(int _k): k(_k), total(0), frec(len,0){}
    DS(){}
    void add(int i){
        total += frec[p[i]^k];
        frec[p[i]]++;
        //cout << frec[p[i]] << endl;
    }
    void del(int i){
        frec[p[i]]--;
        total -= frec[p[i]^k];
    }
    long long query(){return total;}
};

struct Query {
    int l, r, idx;
    Query(){}
    Query(int _l, int _r, int _idx){
        l = _l;
        r = _r;
        idx = _idx;
    }
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<long long> mo_s_algorithm(vector<Query> queries, int k) {
    vector<long long> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure
    DS ans(k);
    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            ans.add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            //cout << cur_r << " ";
            //cout << p[cur_r] << " ";
            ans.add(cur_r);
        }
        while (cur_l < q.l){
            ans.del(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            ans.del(cur_r);
            cur_r--;
        }
        //cout << endl;
        answers[q.idx] = ans.query();
    }
    return answers;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k;
    while(cin >> n >> m >> k){
        block_size = (int)sqrt((double)n) + 1;
        vector<int> a(n);
        for(auto &i : a)cin >> i;
        p.assign(n + 1, 0);
        for(int i = 1; i < n + 1; i++){
            p[i] = a[i - 1] ^ p[i - 1];
            //cout << p[i] << " ";
        }
        //cout << endl;
        vector<Query> queries(m);
        for(int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            queries[i] = Query(--l,r,i);
        }
        for(auto i: mo_s_algorithm(queries,k)){
            cout << i << endl;
        }
    }
    return 0;
}